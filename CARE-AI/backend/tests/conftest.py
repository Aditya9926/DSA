"""
Test configuration and fixtures.
"""

import pytest
import sys
import os

# Add the backend directory to the path
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', '..'))


@pytest.fixture
def sample_sensor_readings():
    """Sample sensor readings for testing."""
    return [
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


@pytest.fixture
def sample_vitals():
    """Sample vital signs for testing."""
    return {
        "heart_rate": 72,
        "systolic_bp": 120,
        "diastolic_bp": 80,
        "oxygen_saturation": 98,
        "temperature": 37,
        "respiratory_rate": 16
    }


@pytest.fixture
def sample_user():
    """Sample user data for testing."""
    return {
        "user_id": "test-user-001",
        "email": "test@example.com",
        "first_name": "Test",
        "last_name": "User",
        "role": "elderly"
    }
