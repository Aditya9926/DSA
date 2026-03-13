"""
Medication Reminder API
=======================

Endpoints for smart medication management and reminders.
"""

from fastapi import APIRouter, HTTPException, BackgroundTasks
from pydantic import BaseModel, Field
from typing import List, Optional
from datetime import datetime, time, date
from enum import Enum
import logging

router = APIRouter()
logger = logging.getLogger(__name__)


class FrequencyType(str, Enum):
    ONCE_DAILY = "once_daily"
    TWICE_DAILY = "twice_daily"
    THREE_TIMES_DAILY = "three_times_daily"
    EVERY_X_HOURS = "every_x_hours"
    AS_NEEDED = "as_needed"
    WEEKLY = "weekly"


class MedicationStatus(str, Enum):
    PENDING = "pending"
    TAKEN = "taken"
    MISSED = "missed"
    SKIPPED = "skipped"


class Medication(BaseModel):
    """Medication details."""
    medication_id: Optional[str] = None
    name: str
    dosage: str
    frequency: FrequencyType
    times: List[str] = Field(..., description="Times in HH:MM format")
    instructions: Optional[str] = None
    start_date: date
    end_date: Optional[date] = None
    refill_reminder_days: int = Field(default=7, ge=1)
    remaining_pills: Optional[int] = None


class MedicationSchedule(BaseModel):
    """User's medication schedule."""
    user_id: str
    medications: List[Medication]


class MedicationLog(BaseModel):
    """Log entry for medication intake."""
    user_id: str
    medication_id: str
    scheduled_time: datetime
    actual_time: Optional[datetime] = None
    status: MedicationStatus
    notes: Optional[str] = None


class ReminderSettings(BaseModel):
    """Reminder notification settings."""
    user_id: str
    reminder_before_minutes: int = Field(default=15, ge=5, le=60)
    reminder_after_minutes: int = Field(default=30, ge=5, le=120)
    voice_reminder_enabled: bool = True
    push_notification_enabled: bool = True
    caregiver_notification_on_miss: bool = True
    escalation_contacts: List[str] = []


@router.post("/schedule")
async def create_medication_schedule(schedule: MedicationSchedule):
    """
    Create or update medication schedule for a user.
    """
    # In production, save to database
    return {
        "message": "Medication schedule created successfully",
        "user_id": schedule.user_id,
        "medications_count": len(schedule.medications),
        "next_reminder": "2024-01-15T08:00:00Z"
    }


@router.get("/schedule/{user_id}")
async def get_medication_schedule(user_id: str):
    """
    Get medication schedule for a user.
    """
    # Mock data
    return {
        "user_id": user_id,
        "medications": [
            {
                "medication_id": "med-001",
                "name": "Metformin",
                "dosage": "500mg",
                "frequency": "twice_daily",
                "times": ["08:00", "20:00"],
                "instructions": "Take with food",
                "remaining_pills": 45
            },
            {
                "medication_id": "med-002",
                "name": "Lisinopril",
                "dosage": "10mg",
                "frequency": "once_daily",
                "times": ["08:00"],
                "instructions": "Take in the morning",
                "remaining_pills": 28
            },
            {
                "medication_id": "med-003",
                "name": "Aspirin",
                "dosage": "81mg",
                "frequency": "once_daily",
                "times": ["08:00"],
                "instructions": "Take with water",
                "remaining_pills": 60
            }
        ]
    }


@router.post("/log")
async def log_medication_intake(
    log: MedicationLog,
    background_tasks: BackgroundTasks
):
    """
    Log medication intake.
    """
    # Notify caregiver if medication was missed
    if log.status == MedicationStatus.MISSED:
        background_tasks.add_task(
            notify_caregiver_missed_medication,
            log.user_id,
            log.medication_id
        )
    
    return {
        "message": "Medication logged successfully",
        "log_id": "log-12345",
        "status": log.status,
        "timestamp": datetime.utcnow()
    }


async def notify_caregiver_missed_medication(user_id: str, medication_id: str):
    """Background task to notify caregiver of missed medication."""
    logger.info(f"Notifying caregiver: User {user_id} missed medication {medication_id}")


@router.get("/today/{user_id}")
async def get_today_medications(user_id: str):
    """
    Get today's medication schedule with status.
    """
    return {
        "user_id": user_id,
        "date": date.today().isoformat(),
        "medications": [
            {
                "medication_id": "med-001",
                "name": "Metformin",
                "dosage": "500mg",
                "scheduled_time": "08:00",
                "status": "taken",
                "taken_at": "08:05"
            },
            {
                "medication_id": "med-002",
                "name": "Lisinopril",
                "dosage": "10mg",
                "scheduled_time": "08:00",
                "status": "taken",
                "taken_at": "08:05"
            },
            {
                "medication_id": "med-001",
                "name": "Metformin",
                "dosage": "500mg",
                "scheduled_time": "20:00",
                "status": "pending",
                "taken_at": None
            }
        ],
        "adherence_today": "67%",
        "next_medication": {
            "name": "Metformin",
            "time": "20:00",
            "in_minutes": 240
        }
    }


@router.get("/adherence/{user_id}")
async def get_medication_adherence(
    user_id: str,
    days: int = 30
):
    """
    Get medication adherence statistics.
    """
    return {
        "user_id": user_id,
        "period_days": days,
        "overall_adherence": 89.5,
        "by_medication": [
            {"name": "Metformin", "adherence": 92.0},
            {"name": "Lisinopril", "adherence": 88.0},
            {"name": "Aspirin", "adherence": 88.5}
        ],
        "missed_doses": 7,
        "total_doses": 67,
        "trend": "stable",
        "insights": [
            "Adherence is good overall",
            "Evening doses are occasionally missed",
            "Consider setting additional reminders for 8 PM"
        ]
    }


@router.post("/reminder/settings")
async def update_reminder_settings(settings: ReminderSettings):
    """
    Update medication reminder settings.
    """
    return {
        "message": "Reminder settings updated",
        "user_id": settings.user_id,
        "settings": settings.model_dump()
    }


@router.get("/refills/{user_id}")
async def get_refill_reminders(user_id: str):
    """
    Get medications that need refilling soon.
    """
    return {
        "user_id": user_id,
        "refills_needed": [
            {
                "medication_id": "med-002",
                "name": "Lisinopril",
                "remaining_pills": 5,
                "days_remaining": 5,
                "pharmacy": "CVS Pharmacy",
                "prescription_number": "RX-789456"
            }
        ],
        "upcoming_refills": [
            {
                "medication_id": "med-001",
                "name": "Metformin",
                "remaining_pills": 45,
                "days_remaining": 22
            }
        ]
    }


@router.post("/voice-reminder/{user_id}")
async def trigger_voice_reminder(user_id: str, medication_id: str):
    """
    Trigger a voice reminder for medication.
    """
    return {
        "user_id": user_id,
        "medication_id": medication_id,
        "voice_reminder_sent": True,
        "message": "It's time to take your Metformin 500mg. Please take it with food.",
        "timestamp": datetime.utcnow()
    }
