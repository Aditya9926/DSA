"""
CARE-AI Backend Tests
=====================
"""

import pytest
from datetime import datetime


class TestFallDetection:
    """Tests for fall detection functionality."""
    
    def test_fall_detection_model_initialization(self):
        """Test that fall detection model can be initialized."""
        from backend.app.ml_models.fall_detection_model import FallDetectionModel
        
        model = FallDetectionModel()
        assert model is not None
        assert model.threshold == 0.7
        assert model.window_size == 50
    
    def test_fall_detection_preprocess(self):
        """Test sensor data preprocessing."""
        from backend.app.ml_models.fall_detection_model import FallDetectionModel
        import numpy as np
        
        model = FallDetectionModel()
        
        # Create sample sensor readings
        readings = [
            {
                "accelerometer_x": 0.1,
                "accelerometer_y": 0.2,
                "accelerometer_z": 9.8,
                "gyroscope_x": 0.0,
                "gyroscope_y": 0.0,
                "gyroscope_z": 0.0
            }
            for _ in range(50)
        ]
        
        processed = model.preprocess_data(readings)
        
        assert processed.shape == (1, 50, 6)
        assert isinstance(processed, np.ndarray)
    
    def test_fall_detection_no_fall(self):
        """Test detection with normal walking data (no fall)."""
        from backend.app.ml_models.fall_detection_model import FallDetectionModel
        
        model = FallDetectionModel()
        
        # Normal walking readings
        readings = [
            {
                "accelerometer_x": 0.5,
                "accelerometer_y": 0.3,
                "accelerometer_z": 9.8,
                "gyroscope_x": 0.1,
                "gyroscope_y": 0.1,
                "gyroscope_z": 0.0
            }
            for _ in range(50)
        ]
        
        result = model.detect_fall(readings)
        
        assert result["fall_detected"] == False
        assert result["confidence"] == 0.0
    
    def test_fall_detection_with_fall(self):
        """Test detection with fall data."""
        from backend.app.ml_models.fall_detection_model import FallDetectionModel
        
        model = FallDetectionModel()
        
        # Simulate fall: high acceleration spike followed by stillness
        readings = []
        
        # Normal readings
        for _ in range(40):
            readings.append({
                "accelerometer_x": 0.1,
                "accelerometer_y": 0.1,
                "accelerometer_z": 9.8,
                "gyroscope_x": 0.0,
                "gyroscope_y": 0.0,
                "gyroscope_z": 0.0
            })
        
        # Impact spike (>3g)
        readings.append({
            "accelerometer_x": 15.0,
            "accelerometer_y": 20.0,
            "accelerometer_z": 25.0,
            "gyroscope_x": 3.0,
            "gyroscope_y": 2.0,
            "gyroscope_z": 1.0
        })
        
        # Post-fall stillness
        for _ in range(9):
            readings.append({
                "accelerometer_x": 0.0,
                "accelerometer_y": 0.0,
                "accelerometer_z": 9.8,
                "gyroscope_x": 0.0,
                "gyroscope_y": 0.0,
                "gyroscope_z": 0.0
            })
        
        result = model.detect_fall(readings)
        
        assert result["fall_detected"] == True
        assert result["confidence"] > 0.5
        assert result["severity"] is not None


class TestHealthPrediction:
    """Tests for health prediction functionality."""
    
    def test_health_prediction_model_initialization(self):
        """Test that health prediction model can be initialized."""
        from backend.app.ml_models.health_prediction_model import HealthPredictionModel
        
        model = HealthPredictionModel()
        assert model is not None
    
    def test_health_prediction_normal_vitals(self):
        """Test prediction with normal vital signs."""
        from backend.app.ml_models.health_prediction_model import HealthPredictionModel
        
        model = HealthPredictionModel()
        
        vitals = {
            "heart_rate": 72,
            "systolic_bp": 120,
            "diastolic_bp": 80,
            "oxygen_saturation": 98,
            "temperature": 37,
            "respiratory_rate": 16
        }
        
        result = model.predict_risks(vitals)
        
        assert "health_score" in result
        assert result["health_score"] > 50  # Should be reasonably healthy
        assert "risks" in result
        assert len(result["risks"]) > 0
    
    def test_health_prediction_high_bp(self):
        """Test prediction with high blood pressure."""
        from backend.app.ml_models.health_prediction_model import HealthPredictionModel
        
        model = HealthPredictionModel()
        
        vitals = {
            "heart_rate": 95,
            "systolic_bp": 180,
            "diastolic_bp": 110,
            "oxygen_saturation": 96,
            "temperature": 37,
            "respiratory_rate": 18
        }
        
        result = model.predict_risks(vitals)
        
        # Should detect cardiovascular risk
        cv_risk = next((r for r in result["risks"] if r["condition"] == "cardiovascular_event"), None)
        assert cv_risk is not None
        assert cv_risk["risk_level"] in ["moderate", "high", "critical"]


class TestEmotionDetection:
    """Tests for emotion detection functionality."""
    
    def test_emotion_model_initialization(self):
        """Test that emotion detection model can be initialized."""
        from backend.app.ml_models.emotion_model import EmotionDetectionModel
        
        model = EmotionDetectionModel()
        assert model is not None
        assert len(model.EMOTIONS) == 7
    
    def test_depression_risk_assessment(self):
        """Test depression risk assessment."""
        from backend.app.ml_models.emotion_model import EmotionDetectionModel
        
        model = EmotionDetectionModel()
        
        # Simulate emotion history with high sadness
        emotion_history = [
            {
                "all_emotions": {
                    "happy": 0.1,
                    "sad": 0.5,
                    "neutral": 0.3,
                    "angry": 0.05,
                    "fearful": 0.05,
                    "surprised": 0.0,
                    "disgusted": 0.0
                }
            }
            for _ in range(10)
        ]
        
        result = model.detect_depression_risk(emotion_history)
        
        assert "risk_level" in result
        assert "risk_score" in result
        assert "recommendations" in result


class TestConfiguration:
    """Tests for configuration."""
    
    def test_settings_load(self):
        """Test that settings can be loaded."""
        from backend.app.utils.config import settings
        
        assert settings is not None
        assert settings.APP_NAME == "CARE-AI"
        assert settings.VERSION == "1.0.0"


if __name__ == "__main__":
    pytest.main([__file__, "-v"])
