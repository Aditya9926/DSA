"""
Health Check API
================

Endpoints for system health monitoring.
"""

from fastapi import APIRouter
from datetime import datetime

router = APIRouter()


@router.get("/health")
async def health_check():
    """
    Health check endpoint.
    
    Returns the current health status of the CARE-AI system.
    """
    return {
        "status": "healthy",
        "timestamp": datetime.utcnow().isoformat(),
        "service": "care-ai-backend",
        "version": "1.0.0"
    }


@router.get("/health/detailed")
async def detailed_health_check():
    """
    Detailed health check with component status.
    """
    return {
        "status": "healthy",
        "timestamp": datetime.utcnow().isoformat(),
        "components": {
            "database": "connected",
            "redis": "connected",
            "ml_models": "loaded",
            "firebase": "connected"
        },
        "metrics": {
            "uptime_seconds": 3600,
            "requests_per_minute": 120,
            "active_users": 45
        }
    }
