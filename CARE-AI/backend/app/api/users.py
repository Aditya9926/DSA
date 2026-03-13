"""
Users API
=========

Endpoints for user management.
"""

from fastapi import APIRouter, HTTPException, Depends
from pydantic import BaseModel, Field, EmailStr
from typing import List, Optional
from datetime import datetime, date
from enum import Enum
import logging

router = APIRouter()
logger = logging.getLogger(__name__)


class UserRole(str, Enum):
    ELDERLY = "elderly"
    CAREGIVER = "caregiver"
    FAMILY_MEMBER = "family_member"
    HEALTHCARE_PROVIDER = "healthcare_provider"
    ADMIN = "admin"


class UserProfile(BaseModel):
    """User profile information."""
    user_id: Optional[str] = None
    email: EmailStr
    first_name: str
    last_name: str
    date_of_birth: date
    role: UserRole
    phone: Optional[str] = None
    address: Optional[str] = None
    emergency_info: Optional[str] = None
    medical_conditions: List[str] = []
    blood_type: Optional[str] = None
    allergies: List[str] = []
    primary_caregiver_id: Optional[str] = None
    created_at: Optional[datetime] = None
    updated_at: Optional[datetime] = None


class ElderlyProfile(UserProfile):
    """Extended profile for elderly users."""
    mobility_level: str = Field(default="independent")
    cognitive_status: str = Field(default="normal")
    living_situation: str = Field(default="alone")
    preferred_hospital: Optional[str] = None
    insurance_info: Optional[str] = None
    daily_routine_notes: Optional[str] = None


class CaregiverProfile(UserProfile):
    """Extended profile for caregivers."""
    assigned_elderly: List[str] = []
    qualification: Optional[str] = None
    availability_hours: Optional[str] = None
    specializations: List[str] = []


class DeviceRegistration(BaseModel):
    """Device registration for a user."""
    user_id: str
    device_id: str
    device_type: str  # smartwatch, phone, raspberry_pi, etc.
    device_name: str
    registered_at: datetime = Field(default_factory=datetime.utcnow)
    is_active: bool = True


@router.post("/register")
async def register_user(profile: UserProfile):
    """
    Register a new user.
    """
    profile.user_id = f"user-{datetime.utcnow().timestamp()}"
    profile.created_at = datetime.utcnow()
    profile.updated_at = datetime.utcnow()
    
    return {
        "message": "User registered successfully",
        "user_id": profile.user_id,
        "role": profile.role,
        "email": profile.email
    }


@router.get("/{user_id}")
async def get_user_profile(user_id: str):
    """
    Get user profile.
    """
    # Mock data
    return ElderlyProfile(
        user_id=user_id,
        email="elderly@example.com",
        first_name="Robert",
        last_name="Johnson",
        date_of_birth=date(1945, 5, 15),
        role=UserRole.ELDERLY,
        phone="+1-555-123-4567",
        address="123 Oak Street, Springfield, IL",
        medical_conditions=["Type 2 Diabetes", "Hypertension"],
        blood_type="O+",
        allergies=["Penicillin"],
        mobility_level="independent_with_assistance",
        cognitive_status="mild_impairment",
        living_situation="alone",
        preferred_hospital="Springfield General Hospital",
        primary_caregiver_id="caregiver-001",
        created_at=datetime(2024, 1, 1),
        updated_at=datetime.utcnow()
    ).model_dump()


@router.put("/{user_id}")
async def update_user_profile(user_id: str, profile: UserProfile):
    """
    Update user profile.
    """
    profile.updated_at = datetime.utcnow()
    
    return {
        "message": "Profile updated successfully",
        "user_id": user_id,
        "updated_at": profile.updated_at
    }


@router.get("/{user_id}/caregivers")
async def get_user_caregivers(user_id: str):
    """
    Get caregivers assigned to a user.
    """
    return {
        "user_id": user_id,
        "caregivers": [
            {
                "caregiver_id": "caregiver-001",
                "name": "Sarah Wilson",
                "relationship": "Professional Caregiver",
                "phone": "+1-555-234-5678",
                "is_primary": True,
                "assigned_since": "2024-01-01"
            },
            {
                "caregiver_id": "family-001",
                "name": "John Johnson",
                "relationship": "Son",
                "phone": "+1-555-345-6789",
                "is_primary": False,
                "assigned_since": "2024-01-01"
            }
        ]
    }


@router.post("/{user_id}/devices")
async def register_device(user_id: str, device: DeviceRegistration):
    """
    Register a device for a user.
    """
    return {
        "message": "Device registered successfully",
        "user_id": user_id,
        "device_id": device.device_id,
        "device_type": device.device_type
    }


@router.get("/{user_id}/devices")
async def get_user_devices(user_id: str):
    """
    Get all devices registered to a user.
    """
    return {
        "user_id": user_id,
        "devices": [
            {
                "device_id": "watch-001",
                "device_type": "smartwatch",
                "device_name": "Apple Watch Series 8",
                "is_active": True,
                "last_sync": datetime.utcnow(),
                "battery_level": 85
            },
            {
                "device_id": "rpi-001",
                "device_type": "raspberry_pi",
                "device_name": "Home Hub",
                "is_active": True,
                "last_sync": datetime.utcnow(),
                "status": "online"
            }
        ]
    }


@router.get("/dashboard/{caregiver_id}")
async def get_caregiver_dashboard(caregiver_id: str):
    """
    Get caregiver dashboard with all assigned elderly status.
    """
    return {
        "caregiver_id": caregiver_id,
        "assigned_count": 3,
        "patients": [
            {
                "user_id": "elderly-001",
                "name": "Robert Johnson",
                "status": "normal",
                "last_activity": datetime.utcnow(),
                "pending_alerts": 0,
                "medication_adherence": 92,
                "health_score": 78
            },
            {
                "user_id": "elderly-002",
                "name": "Mary Smith",
                "status": "attention_needed",
                "last_activity": datetime.utcnow(),
                "pending_alerts": 1,
                "medication_adherence": 85,
                "health_score": 72
            },
            {
                "user_id": "elderly-003",
                "name": "James Brown",
                "status": "normal",
                "last_activity": datetime.utcnow(),
                "pending_alerts": 0,
                "medication_adherence": 95,
                "health_score": 82
            }
        ],
        "summary": {
            "total_alerts_today": 3,
            "medications_due": 5,
            "check_ins_completed": 8
        }
    }


@router.get("/family/{family_id}/overview")
async def get_family_overview(family_id: str):
    """
    Get family dashboard overview.
    """
    return {
        "family_id": family_id,
        "elderly_members": [
            {
                "user_id": "elderly-001",
                "name": "Dad (Robert)",
                "current_status": "All Good ✓",
                "health_score": 78,
                "last_check_in": "2 hours ago",
                "today_summary": {
                    "medications_taken": 3,
                    "steps": 2500,
                    "sleep_hours": 7.5
                },
                "recent_alerts": []
            }
        ],
        "notifications": [
            {
                "type": "medication",
                "message": "Dad took morning medication on time",
                "time": "8:05 AM"
            },
            {
                "type": "activity",
                "message": "Dad completed morning walk",
                "time": "9:30 AM"
            }
        ]
    }
