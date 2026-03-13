"""
Database Models
===============

SQLAlchemy models for CARE-AI database.
"""

from sqlalchemy import Column, Integer, String, Float, Boolean, DateTime, ForeignKey, Text, JSON
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import relationship
from datetime import datetime

Base = declarative_base()


class User(Base):
    """User model."""
    __tablename__ = "users"
    
    id = Column(Integer, primary_key=True, index=True)
    user_id = Column(String(50), unique=True, index=True)
    email = Column(String(255), unique=True, index=True)
    hashed_password = Column(String(255))
    first_name = Column(String(100))
    last_name = Column(String(100))
    date_of_birth = Column(DateTime)
    role = Column(String(50))  # elderly, caregiver, family_member, healthcare_provider
    phone = Column(String(20))
    address = Column(Text)
    
    # Medical info
    medical_conditions = Column(JSON, default=lambda: [])
    allergies = Column(JSON, default=lambda: [])
    blood_type = Column(String(10))
    
    # Elderly-specific
    mobility_level = Column(String(50))
    cognitive_status = Column(String(50))
    living_situation = Column(String(50))
    
    is_active = Column(Boolean, default=True)
    created_at = Column(DateTime, default=datetime.utcnow)
    updated_at = Column(DateTime, default=datetime.utcnow, onupdate=datetime.utcnow)
    
    # Relationships
    vital_signs = relationship("VitalSign", back_populates="user")
    fall_events = relationship("FallEvent", back_populates="user")
    medications = relationship("Medication", back_populates="user")
    alerts = relationship("Alert", back_populates="user")


class EmergencyContact(Base):
    """Emergency contact model."""
    __tablename__ = "emergency_contacts"
    
    id = Column(Integer, primary_key=True, index=True)
    user_id = Column(String(50), ForeignKey("users.user_id"))
    name = Column(String(200))
    relationship = Column(String(100))
    phone = Column(String(20))
    email = Column(String(255))
    is_primary = Column(Boolean, default=False)
    notification_preferences = Column(JSON, default=lambda: ["push", "sms"])
    created_at = Column(DateTime, default=datetime.utcnow)


class Device(Base):
    """Registered device model."""
    __tablename__ = "devices"
    
    id = Column(Integer, primary_key=True, index=True)
    device_id = Column(String(100), unique=True, index=True)
    user_id = Column(String(50), ForeignKey("users.user_id"))
    device_type = Column(String(50))  # smartwatch, phone, raspberry_pi
    device_name = Column(String(200))
    is_active = Column(Boolean, default=True)
    last_sync = Column(DateTime)
    registered_at = Column(DateTime, default=datetime.utcnow)


class VitalSign(Base):
    """Vital signs reading model."""
    __tablename__ = "vital_signs"
    
    id = Column(Integer, primary_key=True, index=True)
    user_id = Column(String(50), ForeignKey("users.user_id"))
    timestamp = Column(DateTime, default=datetime.utcnow)
    
    heart_rate = Column(Integer)
    systolic_bp = Column(Integer)
    diastolic_bp = Column(Integer)
    oxygen_saturation = Column(Float)
    temperature = Column(Float)
    respiratory_rate = Column(Integer)
    
    device_id = Column(String(100))
    
    user = relationship("User", back_populates="vital_signs")


class SensorReading(Base):
    """Accelerometer/Gyroscope sensor reading."""
    __tablename__ = "sensor_readings"
    
    id = Column(Integer, primary_key=True, index=True)
    user_id = Column(String(50), ForeignKey("users.user_id"))
    device_id = Column(String(100))
    timestamp = Column(DateTime, default=datetime.utcnow)
    
    accelerometer_x = Column(Float)
    accelerometer_y = Column(Float)
    accelerometer_z = Column(Float)
    gyroscope_x = Column(Float)
    gyroscope_y = Column(Float)
    gyroscope_z = Column(Float)


class FallEvent(Base):
    """Fall event record."""
    __tablename__ = "fall_events"
    
    id = Column(Integer, primary_key=True, index=True)
    event_id = Column(String(50), unique=True, index=True)
    user_id = Column(String(50), ForeignKey("users.user_id"))
    timestamp = Column(DateTime, default=datetime.utcnow)
    
    fall_type = Column(String(50))
    severity = Column(String(20))
    confidence = Column(Float)
    max_acceleration = Column(Float)
    
    location = Column(String(200))
    response_time_seconds = Column(Integer)
    outcome = Column(String(50))
    notes = Column(Text)
    
    user = relationship("User", back_populates="fall_events")


class Medication(Base):
    """Medication model."""
    __tablename__ = "medications"
    
    id = Column(Integer, primary_key=True, index=True)
    medication_id = Column(String(50), unique=True, index=True)
    user_id = Column(String(50), ForeignKey("users.user_id"))
    
    name = Column(String(200))
    dosage = Column(String(100))
    frequency = Column(String(50))
    times = Column(JSON)  # List of times
    instructions = Column(Text)
    
    start_date = Column(DateTime)
    end_date = Column(DateTime)
    remaining_pills = Column(Integer)
    
    is_active = Column(Boolean, default=True)
    created_at = Column(DateTime, default=datetime.utcnow)
    
    user = relationship("User", back_populates="medications")


class MedicationLog(Base):
    """Medication intake log."""
    __tablename__ = "medication_logs"
    
    id = Column(Integer, primary_key=True, index=True)
    user_id = Column(String(50), ForeignKey("users.user_id"))
    medication_id = Column(String(50), ForeignKey("medications.medication_id"))
    
    scheduled_time = Column(DateTime)
    actual_time = Column(DateTime)
    status = Column(String(20))  # taken, missed, skipped
    notes = Column(Text)
    
    created_at = Column(DateTime, default=datetime.utcnow)


class Alert(Base):
    """Alert model."""
    __tablename__ = "alerts"
    
    id = Column(Integer, primary_key=True, index=True)
    alert_id = Column(String(50), unique=True, index=True)
    user_id = Column(String(50), ForeignKey("users.user_id"))
    
    alert_type = Column(String(50))  # fall, health_risk, medication, loneliness, emergency
    severity = Column(String(20))  # low, medium, high, critical
    title = Column(String(200))
    message = Column(Text)
    location = Column(String(200))
    
    status = Column(String(20), default="pending")
    acknowledged_by = Column(String(50))
    acknowledged_at = Column(DateTime)
    resolved_at = Column(DateTime)
    notes = Column(Text)
    
    created_at = Column(DateTime, default=datetime.utcnow)
    
    user = relationship("User", back_populates="alerts")


class EmotionRecord(Base):
    """Emotion detection record."""
    __tablename__ = "emotion_records"
    
    id = Column(Integer, primary_key=True, index=True)
    user_id = Column(String(50), ForeignKey("users.user_id"))
    timestamp = Column(DateTime, default=datetime.utcnow)
    
    source = Column(String(20))  # voice, facial, self_reported
    detected_emotion = Column(String(50))
    confidence = Column(Float)
    all_emotions = Column(JSON)
    
    loneliness_score = Column(Float)
    energy_level = Column(String(20))
    
    notes = Column(Text)


class DailyActivity(Base):
    """Daily activity summary."""
    __tablename__ = "daily_activities"
    
    id = Column(Integer, primary_key=True, index=True)
    user_id = Column(String(50), ForeignKey("users.user_id"))
    date = Column(DateTime)
    
    steps = Column(Integer, default=0)
    active_minutes = Column(Integer, default=0)
    calories_burned = Column(Integer, default=0)
    distance_km = Column(Float, default=0)
    floors_climbed = Column(Integer, default=0)
    
    sleep_hours = Column(Float)
    deep_sleep_hours = Column(Float)
    sleep_quality_score = Column(Float)
    
    social_interactions = Column(Integer, default=0)
    mood_score = Column(Integer)  # 1-10
    
    created_at = Column(DateTime, default=datetime.utcnow)


class HealthPrediction(Base):
    """Health prediction history."""
    __tablename__ = "health_predictions"
    
    id = Column(Integer, primary_key=True, index=True)
    user_id = Column(String(50), ForeignKey("users.user_id"))
    timestamp = Column(DateTime, default=datetime.utcnow)
    
    health_score = Column(Float)
    cardiovascular_risk = Column(Float)
    stroke_risk = Column(Float)
    weakness_risk = Column(Float)
    
    predictions_data = Column(JSON)
    recommendations = Column(JSON)
