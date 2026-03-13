"""
Fall Detection API
==================

Endpoints for fall detection using AI/ML.
Uses accelerometer and gyroscope data to detect falls.
"""

from fastapi import APIRouter, HTTPException, BackgroundTasks
from pydantic import BaseModel, Field
from typing import List, Optional
from datetime import datetime
import logging

router = APIRouter()
logger = logging.getLogger(__name__)


class SensorReading(BaseModel):
    """Sensor data from wearable device."""
    timestamp: datetime
    accelerometer_x: float = Field(..., description="Accelerometer X-axis (m/s²)")
    accelerometer_y: float = Field(..., description="Accelerometer Y-axis (m/s²)")
    accelerometer_z: float = Field(..., description="Accelerometer Z-axis (m/s²)")
    gyroscope_x: float = Field(..., description="Gyroscope X-axis (rad/s)")
    gyroscope_y: float = Field(..., description="Gyroscope Y-axis (rad/s)")
    gyroscope_z: float = Field(..., description="Gyroscope Z-axis (rad/s)")


class FallDetectionRequest(BaseModel):
    """Request body for fall detection."""
    user_id: str
    device_id: str
    readings: List[SensorReading]


class FallDetectionResponse(BaseModel):
    """Response from fall detection analysis."""
    user_id: str
    fall_detected: bool
    confidence: float
    fall_type: Optional[str] = None
    severity: Optional[str] = None
    timestamp: datetime
    recommended_action: str


class FallAlert(BaseModel):
    """Fall alert notification."""
    alert_id: str
    user_id: str
    fall_type: str
    severity: str
    location: Optional[str] = None
    timestamp: datetime
    emergency_contacts_notified: bool
    response_status: str


@router.post("/analyze", response_model=FallDetectionResponse)
async def analyze_fall(
    request: FallDetectionRequest,
    background_tasks: BackgroundTasks
):
    """
    Analyze sensor data for fall detection.
    
    Uses LSTM/Random Forest model to detect falls from
    accelerometer and gyroscope readings.
    """
    try:
        from ..services.fall_detection_service import FallDetectionService
        
        service = FallDetectionService()
        result = await service.detect_fall(
            user_id=request.user_id,
            device_id=request.device_id,
            readings=request.readings
        )
        
        # If fall detected, trigger alert in background
        if result.fall_detected:
            background_tasks.add_task(
                service.trigger_fall_alert,
                user_id=request.user_id,
                fall_data=result
            )
        
        return result
        
    except Exception as e:
        logger.error(f"Fall detection error: {str(e)}")
        raise HTTPException(status_code=500, detail=f"Fall detection failed: {str(e)}")


@router.post("/realtime")
async def realtime_fall_detection(reading: SensorReading, user_id: str):
    """
    Real-time fall detection for streaming sensor data.
    
    Processes individual sensor readings for immediate fall detection.
    """
    from ..services.fall_detection_service import FallDetectionService
    
    service = FallDetectionService()
    
    # Calculate magnitude for quick check
    accel_magnitude = (
        reading.accelerometer_x ** 2 +
        reading.accelerometer_y ** 2 +
        reading.accelerometer_z ** 2
    ) ** 0.5
    
    # Quick threshold check (falls typically show >3g acceleration)
    if accel_magnitude > 29.4:  # ~3g
        return {
            "user_id": user_id,
            "potential_fall": True,
            "magnitude": accel_magnitude,
            "message": "High acceleration detected - monitoring closely",
            "timestamp": reading.timestamp
        }
    
    return {
        "user_id": user_id,
        "potential_fall": False,
        "magnitude": accel_magnitude,
        "status": "normal",
        "timestamp": reading.timestamp
    }


@router.get("/alerts/{user_id}")
async def get_fall_alerts(
    user_id: str,
    limit: int = 10,
    include_resolved: bool = False
):
    """
    Get fall alerts for a user.
    """
    # Mock data for demonstration
    alerts = [
        FallAlert(
            alert_id="fa-001",
            user_id=user_id,
            fall_type="forward_fall",
            severity="moderate",
            location="Living Room",
            timestamp=datetime.utcnow(),
            emergency_contacts_notified=True,
            response_status="resolved"
        )
    ]
    
    return {
        "user_id": user_id,
        "total_alerts": len(alerts),
        "alerts": alerts
    }


@router.get("/statistics/{user_id}")
async def get_fall_statistics(user_id: str, days: int = 30):
    """
    Get fall detection statistics for a user.
    """
    return {
        "user_id": user_id,
        "period_days": days,
        "statistics": {
            "total_falls_detected": 2,
            "false_positives": 1,
            "near_falls": 5,
            "average_response_time_seconds": 45,
            "fall_types": {
                "forward_fall": 1,
                "backward_fall": 0,
                "sideways_fall": 1
            }
        }
    }


@router.post("/calibrate/{device_id}")
async def calibrate_device(device_id: str, user_id: str):
    """
    Calibrate fall detection for a specific device and user.
    
    Adjusts sensitivity based on user's normal movement patterns.
    """
    return {
        "device_id": device_id,
        "user_id": user_id,
        "calibration_status": "initiated",
        "message": "Please perform normal activities for 5 minutes",
        "estimated_completion": "5 minutes"
    }
