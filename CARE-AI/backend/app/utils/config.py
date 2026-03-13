"""
Configuration Settings
======================

Application configuration using Pydantic settings.
"""

from pydantic_settings import BaseSettings
from typing import List
import os


class Settings(BaseSettings):
    """Application settings."""
    
    # Application
    APP_NAME: str = "CARE-AI"
    VERSION: str = "1.0.0"
    ENVIRONMENT: str = "development"
    DEBUG: bool = True
    
    # API
    API_PREFIX: str = "/api/v1"
    ALLOWED_ORIGINS: List[str] = ["http://localhost:3000", "http://localhost:8080"]
    
    # Database
    DATABASE_URL: str = "postgresql+asyncpg://user:password@localhost:5432/careai"
    
    # Redis
    REDIS_URL: str = "redis://localhost:6379/0"
    
    # Firebase
    FIREBASE_CREDENTIALS_PATH: str = ""
    
    # ML Models
    MODELS_PATH: str = "./models"
    FALL_DETECTION_MODEL_PATH: str = "./models/fall_detection_lstm.h5"
    HEALTH_PREDICTION_MODEL_PATH: str = "./models/health_prediction_rf.joblib"
    EMOTION_MODEL_PATH: str = "./models/emotion_cnn.h5"
    
    # Security
    SECRET_KEY: str = "your-secret-key-change-in-production"
    ACCESS_TOKEN_EXPIRE_MINUTES: int = 30
    
    # Alert Settings
    FALL_DETECTION_THRESHOLD: float = 0.7
    HEALTH_RISK_ALERT_THRESHOLD: float = 0.6
    LONELINESS_ALERT_THRESHOLD: float = 0.7
    
    # Notification Settings
    ENABLE_SMS_NOTIFICATIONS: bool = True
    ENABLE_CALL_NOTIFICATIONS: bool = True
    ENABLE_PUSH_NOTIFICATIONS: bool = True
    
    class Config:
        env_file = ".env"
        case_sensitive = True


# Create settings instance
settings = Settings()
