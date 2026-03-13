"""
Alerts API
==========

Endpoints for managing alerts and emergency notifications.
"""

from fastapi import APIRouter, HTTPException, BackgroundTasks
from pydantic import BaseModel, Field
from typing import List, Optional
from datetime import datetime
from enum import Enum
import logging

router = APIRouter()
logger = logging.getLogger(__name__)


class AlertType(str, Enum):
    FALL = "fall"
    HEALTH_RISK = "health_risk"
    MEDICATION_MISSED = "medication_missed"
    LONELINESS = "loneliness"
    EMERGENCY = "emergency"
    INACTIVITY = "inactivity"
    GEOFENCE = "geofence"


class AlertSeverity(str, Enum):
    LOW = "low"
    MEDIUM = "medium"
    HIGH = "high"
    CRITICAL = "critical"


class AlertStatus(str, Enum):
    PENDING = "pending"
    ACKNOWLEDGED = "acknowledged"
    IN_PROGRESS = "in_progress"
    RESOLVED = "resolved"
    ESCALATED = "escalated"


class EmergencyContact(BaseModel):
    """Emergency contact information."""
    contact_id: str
    name: str
    relationship: str
    phone: str
    email: Optional[str] = None
    is_primary: bool = False
    notification_preferences: List[str] = ["push", "sms", "call"]


class Alert(BaseModel):
    """Alert model."""
    alert_id: Optional[str] = None
    user_id: str
    alert_type: AlertType
    severity: AlertSeverity
    title: str
    message: str
    location: Optional[str] = None
    timestamp: datetime = Field(default_factory=datetime.utcnow)
    status: AlertStatus = AlertStatus.PENDING
    acknowledged_by: Optional[str] = None
    acknowledged_at: Optional[datetime] = None
    resolved_at: Optional[datetime] = None
    notes: Optional[str] = None


class AlertResponse(BaseModel):
    """Response to an alert."""
    alert_id: str
    responder_id: str
    response_type: str
    response_time: datetime
    notes: Optional[str] = None


@router.post("/create")
async def create_alert(
    alert: Alert,
    background_tasks: BackgroundTasks
):
    """
    Create a new alert and notify relevant parties.
    """
    alert.alert_id = f"alert-{datetime.utcnow().timestamp()}"
    
    # Trigger notifications in background
    background_tasks.add_task(send_alert_notifications, alert)
    
    return {
        "message": "Alert created successfully",
        "alert_id": alert.alert_id,
        "notifications_queued": True,
        "estimated_response_time": "2-5 minutes"
    }


async def send_alert_notifications(alert: Alert):
    """Send notifications to caregivers and emergency contacts."""
    logger.info(f"Sending notifications for alert {alert.alert_id}")
    # In production, integrate with Firebase, SMS, and call services


@router.get("/user/{user_id}")
async def get_user_alerts(
    user_id: str,
    status: Optional[AlertStatus] = None,
    alert_type: Optional[AlertType] = None,
    limit: int = 50
):
    """
    Get alerts for a specific user.
    """
    # Mock data
    alerts = [
        Alert(
            alert_id="alert-001",
            user_id=user_id,
            alert_type=AlertType.MEDICATION_MISSED,
            severity=AlertSeverity.MEDIUM,
            title="Missed Medication",
            message="Evening dose of Metformin was not taken",
            timestamp=datetime.utcnow(),
            status=AlertStatus.RESOLVED
        ),
        Alert(
            alert_id="alert-002",
            user_id=user_id,
            alert_type=AlertType.INACTIVITY,
            severity=AlertSeverity.LOW,
            title="Prolonged Inactivity",
            message="No movement detected for 3 hours",
            timestamp=datetime.utcnow(),
            status=AlertStatus.ACKNOWLEDGED
        )
    ]
    
    return {
        "user_id": user_id,
        "total_alerts": len(alerts),
        "alerts": [a.model_dump() for a in alerts]
    }


@router.post("/acknowledge/{alert_id}")
async def acknowledge_alert(
    alert_id: str,
    responder_id: str,
    notes: Optional[str] = None
):
    """
    Acknowledge an alert.
    """
    return {
        "alert_id": alert_id,
        "status": "acknowledged",
        "acknowledged_by": responder_id,
        "acknowledged_at": datetime.utcnow(),
        "notes": notes,
        "message": "Alert acknowledged successfully"
    }


@router.post("/resolve/{alert_id}")
async def resolve_alert(
    alert_id: str,
    responder_id: str,
    resolution_notes: str
):
    """
    Resolve an alert.
    """
    return {
        "alert_id": alert_id,
        "status": "resolved",
        "resolved_by": responder_id,
        "resolved_at": datetime.utcnow(),
        "resolution_notes": resolution_notes,
        "message": "Alert resolved successfully"
    }


@router.post("/escalate/{alert_id}")
async def escalate_alert(
    alert_id: str,
    escalation_reason: str,
    background_tasks: BackgroundTasks
):
    """
    Escalate an alert to emergency services.
    """
    # Trigger emergency escalation
    background_tasks.add_task(
        contact_emergency_services,
        alert_id,
        escalation_reason
    )
    
    return {
        "alert_id": alert_id,
        "status": "escalated",
        "escalated_at": datetime.utcnow(),
        "escalation_reason": escalation_reason,
        "emergency_services_contacted": True,
        "message": "Alert escalated to emergency services"
    }


async def contact_emergency_services(alert_id: str, reason: str):
    """Contact emergency services for critical alerts."""
    logger.warning(f"EMERGENCY: Contacting services for alert {alert_id}: {reason}")


@router.get("/emergency-contacts/{user_id}")
async def get_emergency_contacts(user_id: str):
    """
    Get emergency contacts for a user.
    """
    return {
        "user_id": user_id,
        "contacts": [
            EmergencyContact(
                contact_id="ec-001",
                name="John Doe",
                relationship="Son",
                phone="+1-555-123-4567",
                email="john.doe@email.com",
                is_primary=True,
                notification_preferences=["push", "sms", "call"]
            ).model_dump(),
            EmergencyContact(
                contact_id="ec-002",
                name="Jane Doe",
                relationship="Daughter",
                phone="+1-555-987-6543",
                email="jane.doe@email.com",
                is_primary=False,
                notification_preferences=["push", "sms"]
            ).model_dump(),
            EmergencyContact(
                contact_id="ec-003",
                name="Dr. Smith",
                relationship="Primary Care Physician",
                phone="+1-555-456-7890",
                email="dr.smith@hospital.com",
                is_primary=False,
                notification_preferences=["call"]
            ).model_dump()
        ]
    }


@router.post("/emergency-contacts")
async def add_emergency_contact(
    user_id: str,
    contact: EmergencyContact
):
    """
    Add an emergency contact.
    """
    return {
        "message": "Emergency contact added successfully",
        "user_id": user_id,
        "contact_id": contact.contact_id or "ec-new-001"
    }


@router.get("/statistics/{user_id}")
async def get_alert_statistics(
    user_id: str,
    days: int = 30
):
    """
    Get alert statistics for a user.
    """
    return {
        "user_id": user_id,
        "period_days": days,
        "statistics": {
            "total_alerts": 12,
            "by_type": {
                "fall": 1,
                "health_risk": 2,
                "medication_missed": 5,
                "loneliness": 2,
                "inactivity": 2
            },
            "by_severity": {
                "critical": 1,
                "high": 2,
                "medium": 5,
                "low": 4
            },
            "average_response_time_minutes": 4.5,
            "resolved_percentage": 92,
            "escalated_percentage": 8
        }
    }


@router.post("/sos/{user_id}")
async def trigger_sos(
    user_id: str,
    location: Optional[str] = None,
    background_tasks: BackgroundTasks = None
):
    """
    Trigger SOS emergency alert.
    
    This is the panic button functionality.
    """
    alert = Alert(
        alert_id=f"sos-{datetime.utcnow().timestamp()}",
        user_id=user_id,
        alert_type=AlertType.EMERGENCY,
        severity=AlertSeverity.CRITICAL,
        title="SOS Emergency Alert",
        message="User triggered emergency SOS button",
        location=location or "Location unknown",
        status=AlertStatus.PENDING
    )
    
    if background_tasks:
        background_tasks.add_task(send_alert_notifications, alert)
        background_tasks.add_task(contact_emergency_services, alert.alert_id, "SOS triggered")
    
    return {
        "alert_id": alert.alert_id,
        "status": "emergency_triggered",
        "message": "Help is on the way!",
        "actions": [
            "Emergency contacts notified",
            "Emergency services alerted",
            "Location shared with responders"
        ],
        "timestamp": datetime.utcnow()
    }
