"""
Fall Detection Service
======================

Business logic for fall detection functionality.
"""

from typing import List, Dict, Any
from datetime import datetime
import logging

from ..ml_models.fall_detection_model import get_fall_detection_model
from .notification_service import NotificationService

logger = logging.getLogger(__name__)


class FallDetectionService:
    """Service for fall detection and alerting."""
    
    def __init__(self):
        self.model = get_fall_detection_model()
        self.notification_service = NotificationService()
    
    async def detect_fall(
        self,
        user_id: str,
        device_id: str,
        readings: List[Any]
    ) -> Dict[str, Any]:
        """
        Detect falls from sensor readings.
        
        Args:
            user_id: User identifier
            device_id: Device identifier
            readings: List of sensor readings
            
        Returns:
            Fall detection result
        """
        logger.info(f"Analyzing fall detection for user {user_id}")
        
        # Convert readings to dict format
        readings_dict = [
            {
                "accelerometer_x": r.accelerometer_x,
                "accelerometer_y": r.accelerometer_y,
                "accelerometer_z": r.accelerometer_z,
                "gyroscope_x": r.gyroscope_x,
                "gyroscope_y": r.gyroscope_y,
                "gyroscope_z": r.gyroscope_z,
                "timestamp": r.timestamp
            }
            for r in readings
        ]
        
        # Run detection
        result = self.model.detect_fall(readings_dict)
        
        # Build response
        return {
            "user_id": user_id,
            "fall_detected": result["fall_detected"],
            "confidence": result["confidence"],
            "fall_type": result.get("fall_type"),
            "severity": result.get("severity"),
            "timestamp": datetime.utcnow(),
            "recommended_action": self._get_recommended_action(result)
        }
    
    def _get_recommended_action(self, detection_result: Dict) -> str:
        """Get recommended action based on detection result."""
        if not detection_result["fall_detected"]:
            return "No action needed"
        
        severity = detection_result.get("severity", "unknown")
        
        if severity == "severe":
            return "Emergency services contacted. Stay still and help is on the way."
        elif severity == "moderate":
            return "Alert sent to caregivers. Please confirm if you need assistance."
        else:
            return "Please confirm you are okay. If not, press SOS button."
    
    async def trigger_fall_alert(
        self,
        user_id: str,
        fall_data: Dict[str, Any]
    ):
        """
        Trigger fall alert and notify relevant parties.
        
        Args:
            user_id: User identifier
            fall_data: Fall detection data
        """
        logger.warning(f"FALL DETECTED for user {user_id}: {fall_data}")
        
        # Create alert
        alert = {
            "type": "fall",
            "user_id": user_id,
            "severity": fall_data.get("severity", "unknown"),
            "fall_type": fall_data.get("fall_type", "unknown"),
            "confidence": fall_data.get("confidence", 0),
            "timestamp": datetime.utcnow().isoformat()
        }
        
        # Send notifications
        await self.notification_service.send_emergency_alert(user_id, alert)
        
        # Log to database (in production)
        # await self.db.save_fall_event(alert)
        
        logger.info(f"Fall alert triggered and notifications sent for user {user_id}")
    
    async def get_fall_history(
        self,
        user_id: str,
        limit: int = 10
    ) -> List[Dict[str, Any]]:
        """Get fall history for a user."""
        # In production, fetch from database
        return [
            {
                "event_id": "fall-001",
                "timestamp": datetime.utcnow(),
                "fall_type": "forward_fall",
                "severity": "mild",
                "response_time_seconds": 45,
                "outcome": "resolved"
            }
        ]
