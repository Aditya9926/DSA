"""
Health Prediction Service
=========================

Business logic for health risk prediction.
"""

from typing import Dict, Any, Optional
from datetime import datetime
import logging

from ..ml_models.health_prediction_model import get_health_prediction_model

logger = logging.getLogger(__name__)


class HealthPredictionService:
    """Service for health risk prediction."""
    
    def __init__(self):
        self.model = get_health_prediction_model()
    
    async def predict_risks(self, request) -> Dict[str, Any]:
        """
        Predict health risks for a user.
        
        Args:
            request: HealthPredictionRequest with vitals and history
            
        Returns:
            Health prediction response
        """
        logger.info(f"Predicting health risks for user {request.user_id}")
        
        # Extract data from request
        vitals = {
            "heart_rate": request.vital_signs.heart_rate,
            "systolic_bp": request.vital_signs.systolic_bp,
            "diastolic_bp": request.vital_signs.diastolic_bp,
            "oxygen_saturation": request.vital_signs.oxygen_saturation,
            "temperature": request.vital_signs.temperature,
            "respiratory_rate": request.vital_signs.respiratory_rate
        }
        
        sleep_history = None
        if request.sleep_history:
            sleep_history = [
                {
                    "total_sleep_hours": s.total_sleep_hours,
                    "deep_sleep_hours": s.deep_sleep_hours,
                    "rem_sleep_hours": s.rem_sleep_hours,
                    "light_sleep_hours": s.light_sleep_hours,
                    "awakenings": s.awakenings
                }
                for s in request.sleep_history
            ]
        
        activity_history = None
        if request.activity_history:
            activity_history = [
                {
                    "steps": a.steps,
                    "active_minutes": a.active_minutes,
                    "calories_burned": a.calories_burned
                }
                for a in request.activity_history
            ]
        
        # Get predictions from model
        prediction = self.model.predict_risks(
            vitals=vitals,
            sleep_history=sleep_history,
            activity_history=activity_history,
            medical_history=request.medical_history
        )
        
        # Build response
        return {
            "user_id": request.user_id,
            "timestamp": datetime.utcnow(),
            "overall_health_score": prediction["health_score"],
            "risks": prediction["risks"],
            "immediate_concerns": prediction["immediate_concerns"],
            "lifestyle_recommendations": prediction["lifestyle_recommendations"]
        }
    
    async def get_health_trends(
        self,
        user_id: str,
        metric: str,
        days: int = 30
    ) -> Dict[str, Any]:
        """Get health trends over time."""
        # In production, fetch from database and calculate trends
        return {
            "user_id": user_id,
            "metric": metric,
            "period_days": days,
            "trend": "stable",
            "data_points": []
        }
    
    async def generate_health_report(
        self,
        user_id: str,
        start_date: Optional[str] = None,
        end_date: Optional[str] = None
    ) -> Dict[str, Any]:
        """Generate comprehensive health report."""
        # In production, aggregate data and generate report
        return {
            "user_id": user_id,
            "report_date": datetime.utcnow(),
            "summary": "Health status stable",
            "recommendations": []
        }
