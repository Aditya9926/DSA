"""
CARE-AI Main Application
========================

FastAPI application entry point for the CARE-AI system.
"""

from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from contextlib import asynccontextmanager
import logging

from .api import health, fall_detection, health_prediction, medication, emotion, alerts, users
from .utils.config import settings
from .utils.logger import setup_logging

# Setup logging
setup_logging()
logger = logging.getLogger(__name__)


@asynccontextmanager
async def lifespan(app: FastAPI):
    """Application lifespan manager."""
    logger.info("🚀 Starting CARE-AI System...")
    logger.info(f"Environment: {settings.ENVIRONMENT}")
    
    # Initialize ML models on startup
    from .ml_models import model_loader
    await model_loader.load_all_models()
    
    yield
    
    logger.info("👋 Shutting down CARE-AI System...")


# Create FastAPI application
app = FastAPI(
    title="CARE-AI API",
    description="Intelligent Companion for Elderly Health & Safety",
    version="1.0.0",
    docs_url="/api/docs",
    redoc_url="/api/redoc",
    lifespan=lifespan
)

# CORS Configuration
app.add_middleware(
    CORSMiddleware,
    allow_origins=settings.ALLOWED_ORIGINS,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# Include API routers
app.include_router(health.router, prefix="/api/v1", tags=["Health Check"])
app.include_router(users.router, prefix="/api/v1/users", tags=["Users"])
app.include_router(fall_detection.router, prefix="/api/v1/fall-detection", tags=["Fall Detection"])
app.include_router(health_prediction.router, prefix="/api/v1/health-prediction", tags=["Health Prediction"])
app.include_router(medication.router, prefix="/api/v1/medication", tags=["Medication"])
app.include_router(emotion.router, prefix="/api/v1/emotion", tags=["Emotion Detection"])
app.include_router(alerts.router, prefix="/api/v1/alerts", tags=["Alerts"])


@app.get("/")
async def root():
    """Root endpoint."""
    return {
        "message": "Welcome to CARE-AI API",
        "version": "1.0.0",
        "docs": "/api/docs",
        "status": "healthy"
    }


@app.get("/api/v1/system/status")
async def system_status():
    """Get system status and loaded models."""
    from .ml_models import model_loader
    return {
        "status": "operational",
        "models_loaded": model_loader.get_loaded_models(),
        "version": "1.0.0"
    }
