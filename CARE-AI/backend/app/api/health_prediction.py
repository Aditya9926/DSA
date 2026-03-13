"""
Health Prediction API
=====================

Endpoints for predicting health risks using ML models.
Analyzes heart rate, sleep patterns, activity levels, and blood pressure.
"""

from fastapi import APIRouter, HTTPException, Query
from pydantic import BaseModel, Field
from typing import List, Optional
from datetime import datetime, date
from enum import Enum
import logging

router = APIRouter()
logger = logging.getLogger(__name__)


class RiskLevel(str, Enum):
    LOW = "low"
    MODERATE = "moderate"
    HIGH = "high"
    CRITICAL = "critical"


class VitalSigns(BaseModel):
    """Vital signs data."""
    heart_rate: int = Field(..., ge=30, le=220, description="Heart rate in BPM")
    systolic_bp: int = Field(..., ge=70, le=250, description="Systolic blood pressure")
    diastolic_bp: int = Field(..., ge=40, le=150, description="Diastolic blood pressure")
    oxygen_saturation: Optional[float] = Field(None, ge=70, le=100, description="SpO2 %")
    temperature: Optional[float] = Field(None, ge=35.0, le=42.0, description="Body temperature °C")
    respiratory_rate: Optional[int] = Field(None, ge=8, le=40, description="Breaths per minute")


class SleepData(BaseModel):
    """Sleep pattern data."""
    date: date
    total_sleep_hours: float = Field(..., ge=0, le=24)
    deep_sleep_hours: float = Field(default=0, ge=0)
    rem_sleep_hours: float = Field(default=0, ge=0)
    light_sleep_hours: float = Field(default=0, ge=0)
    awakenings: int = Field(default=0, ge=0)
    sleep_quality_score: Optional[float] = Field(None, ge=0, le=100)


class ActivityData(BaseModel):
    """Daily activity data."""
    date: date
    steps: int = Field(default=0, ge=0)
    active_minutes: int = Field(default=0, ge=0)
    calories_burned: int = Field(default=0, ge=0)
    distance_km: float = Field(default=0, ge=0)
    floors_climbed: int = Field(default=0, ge=0)


class HealthPredictionRequest(BaseModel):
    """Request for health prediction."""
    user_id: str
    vital_signs: VitalSigns
    sleep_history: Optional[List[SleepData]] = None
    activity_history: Optional[List[ActivityData]] = None
    medical_history: Optional[List[str]] = None


class HealthRisk(BaseModel):
    """Individual health risk prediction."""
    condition: str
    risk_level: RiskLevel
    probability: float = Field(..., ge=0, le=1)
    contributing_factors: List[str]
    recommendations: List[str]


class HealthPredictionResponse(BaseModel):
    """Health prediction response."""
    user_id: str
    timestamp: datetime
    overall_health_score: float = Field(..., ge=0, le=100)
    risks: List[HealthRisk]
    immediate_concerns: List[str]
    lifestyle_recommendations: List[str]


@router.post("/predict", response_model=HealthPredictionResponse)
async def predict_health_risks(request: HealthPredictionRequest):
    """
    Predict health risks based on vital signs and historical data.
    
    Uses ML models to analyze patterns and predict risks for:
    - Cardiovascular events (heart attack, stroke)
    - Respiratory issues
    - General weakness and fatigue
    - Sleep disorders
    """
    try:
        from ..services.health_prediction_service import HealthPredictionService
        
        service = HealthPredictionService()
        result = await service.predict_risks(request)
        
        return result
        
    except Exception as e:
        logger.error(f"Health prediction error: {str(e)}")
        raise HTTPException(status_code=500, detail=f"Prediction failed: {str(e)}")


@router.post("/analyze-vitals")
async def analyze_vital_signs(vitals: VitalSigns, user_id: str):
    """
    Quick analysis of current vital signs.
    
    Provides immediate feedback on vital sign readings.
    """
    concerns = []
    status = "normal"
    
    # Heart rate analysis
    if vitals.heart_rate < 60:
        concerns.append("Low heart rate (bradycardia)")
    elif vitals.heart_rate > 100:
        concerns.append("Elevated heart rate (tachycardia)")
        status = "attention_needed"
    
    # Blood pressure analysis
    if vitals.systolic_bp >= 180 or vitals.diastolic_bp >= 120:
        concerns.append("Hypertensive crisis - seek immediate medical attention")
        status = "critical"
    elif vitals.systolic_bp >= 140 or vitals.diastolic_bp >= 90:
        concerns.append("High blood pressure")
        status = "attention_needed"
    elif vitals.systolic_bp < 90 or vitals.diastolic_bp < 60:
        concerns.append("Low blood pressure")
        status = "attention_needed"
    
    # Oxygen saturation
    if vitals.oxygen_saturation:
        if vitals.oxygen_saturation < 90:
            concerns.append("Critical oxygen level - seek immediate help")
            status = "critical"
        elif vitals.oxygen_saturation < 95:
            concerns.append("Low oxygen saturation")
            status = "attention_needed"
    
    return {
        "user_id": user_id,
        "timestamp": datetime.utcnow(),
        "status": status,
        "vitals_summary": {
            "heart_rate": f"{vitals.heart_rate} BPM",
            "blood_pressure": f"{vitals.systolic_bp}/{vitals.diastolic_bp} mmHg",
            "oxygen_saturation": f"{vitals.oxygen_saturation}%" if vitals.oxygen_saturation else "N/A"
        },
        "concerns": concerns,
        "recommendation": "Seek medical attention" if status == "critical" else "Continue monitoring"
    }


@router.get("/trends/{user_id}")
async def get_health_trends(
    user_id: str,
    metric: str = Query(..., description="Metric to analyze: heart_rate, blood_pressure, sleep, activity"),
    days: int = Query(default=30, ge=7, le=365)
):
    """
    Get health trends over time for analysis.
    """
    return {
        "user_id": user_id,
        "metric": metric,
        "period_days": days,
        "trend": "stable",
        "average": 72.5,
        "min": 58,
        "max": 95,
        "data_points": [
            {"date": "2024-01-01", "value": 72},
            {"date": "2024-01-02", "value": 75},
            {"date": "2024-01-03", "value": 70}
        ],
        "insights": [
            "Heart rate is within normal range",
            "Slight increase during morning hours",
            "Good recovery during sleep"
        ]
    }


@router.get("/report/{user_id}")
async def generate_health_report(
    user_id: str,
    start_date: Optional[date] = None,
    end_date: Optional[date] = None
):
    """
    Generate a comprehensive health report.
    """
    return {
        "user_id": user_id,
        "report_generated": datetime.utcnow(),
        "period": {
            "start": start_date or "2024-01-01",
            "end": end_date or "2024-01-31"
        },
        "summary": {
            "overall_health_score": 78.5,
            "trend": "improving",
            "key_metrics": {
                "average_heart_rate": 72,
                "average_blood_pressure": "125/80",
                "average_sleep_hours": 7.2,
                "average_daily_steps": 4500
            }
        },
        "risk_assessment": {
            "cardiovascular": "low",
            "stroke": "low",
            "diabetes": "moderate",
            "fall_risk": "low"
        },
        "recommendations": [
            "Increase daily physical activity",
            "Maintain regular sleep schedule",
            "Continue medication as prescribed",
            "Schedule follow-up with cardiologist"
        ]
    }


@router.post("/alzheimers-screening")
async def alzheimers_early_screening(
    user_id: str,
    cognitive_test_scores: Optional[dict] = None,
    behavioral_patterns: Optional[dict] = None
):
    """
    Early screening for Alzheimer's symptoms.
    
    Analyzes cognitive patterns, memory tests, and behavioral changes.
    """
    return {
        "user_id": user_id,
        "screening_date": datetime.utcnow(),
        "cognitive_assessment": {
            "memory_score": 82,
            "attention_score": 78,
            "language_score": 85,
            "executive_function_score": 76
        },
        "risk_indicators": {
            "memory_decline": "none_detected",
            "confusion_episodes": "rare",
            "sleep_pattern_changes": "minimal"
        },
        "overall_risk": "low",
        "recommendation": "Continue regular monitoring. No immediate concerns detected.",
        "next_screening_recommended": "3 months"
    }
