"""
CARE-AI IoT Sensor Integration
==============================

Code for collecting sensor data from wearable devices and smart home sensors.
Runs on Raspberry Pi as IoT hub.
"""

import asyncio
import json
import time
from datetime import datetime
from dataclasses import dataclass, asdict
from typing import List, Optional, Callable
import logging

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)


@dataclass
class SensorReading:
    """Data class for sensor readings."""
    timestamp: str
    accelerometer_x: float
    accelerometer_y: float
    accelerometer_z: float
    gyroscope_x: float
    gyroscope_y: float
    gyroscope_z: float
    heart_rate: Optional[int] = None
    temperature: Optional[float] = None
    
    def to_dict(self):
        return asdict(self)


class SensorHub:
    """
    IoT Hub for collecting and processing sensor data.
    
    Runs on Raspberry Pi and collects data from:
    - Wearable devices (smartwatch)
    - Environmental sensors
    - Motion detectors
    """
    
    def __init__(self, api_endpoint: str = "http://localhost:8000"):
        self.api_endpoint = api_endpoint
        self.readings_buffer: List[SensorReading] = []
        self.buffer_size = 50
        self.is_running = False
        self.callbacks: List[Callable] = []
        
    def add_callback(self, callback: Callable):
        """Add callback for when readings are collected."""
        self.callbacks.append(callback)
        
    async def start(self):
        """Start collecting sensor data."""
        self.is_running = True
        logger.info("Sensor hub started")
        
        while self.is_running:
            try:
                # Collect sensor reading
                reading = await self._collect_reading()
                self.readings_buffer.append(reading)
                
                # Check for potential fall
                await self._check_fall_indicators(reading)
                
                # Send buffer when full
                if len(self.readings_buffer) >= self.buffer_size:
                    await self._send_buffer()
                    
                # Collect at ~50Hz
                await asyncio.sleep(0.02)
                
            except Exception as e:
                logger.error(f"Error collecting sensor data: {e}")
                await asyncio.sleep(1)
    
    async def stop(self):
        """Stop collecting sensor data."""
        self.is_running = False
        if self.readings_buffer:
            await self._send_buffer()
        logger.info("Sensor hub stopped")
    
    async def _collect_reading(self) -> SensorReading:
        """
        Collect reading from sensors.
        
        In production, this would read from actual hardware:
        - I2C accelerometer/gyroscope (MPU6050)
        - Bluetooth heart rate monitor
        - Temperature sensors
        """
        # Simulate sensor reading (replace with actual hardware interface)
        import random
        
        reading = SensorReading(
            timestamp=datetime.utcnow().isoformat(),
            accelerometer_x=random.gauss(0, 0.5),
            accelerometer_y=random.gauss(0, 0.5),
            accelerometer_z=random.gauss(9.8, 0.3),  # Gravity
            gyroscope_x=random.gauss(0, 0.1),
            gyroscope_y=random.gauss(0, 0.1),
            gyroscope_z=random.gauss(0, 0.1),
            heart_rate=random.randint(65, 80) if random.random() > 0.9 else None,
        )
        
        return reading
    
    async def _check_fall_indicators(self, reading: SensorReading):
        """Quick check for fall indicators."""
        # Calculate acceleration magnitude
        magnitude = (
            reading.accelerometer_x ** 2 +
            reading.accelerometer_y ** 2 +
            reading.accelerometer_z ** 2
        ) ** 0.5
        
        # High acceleration might indicate fall
        if magnitude > 29.4:  # > 3g
            logger.warning(f"High acceleration detected: {magnitude:.2f} m/s²")
            await self._trigger_fall_check()
    
    async def _trigger_fall_check(self):
        """Trigger fall detection analysis."""
        logger.info("Triggering fall detection analysis")
        # In production, send data to backend for ML analysis
        for callback in self.callbacks:
            await callback("potential_fall", self.readings_buffer[-50:])
    
    async def _send_buffer(self):
        """Send buffered readings to backend."""
        if not self.readings_buffer:
            return
            
        data = {
            "user_id": "elderly-001",
            "device_id": "rpi-hub-001",
            "readings": [r.to_dict() for r in self.readings_buffer]
        }
        
        # In production, send to API
        # async with aiohttp.ClientSession() as session:
        #     await session.post(f"{self.api_endpoint}/api/v1/fall-detection/analyze", json=data)
        
        logger.debug(f"Sent {len(self.readings_buffer)} readings to backend")
        self.readings_buffer = []


class HeartRateMonitor:
    """Bluetooth heart rate monitor integration."""
    
    def __init__(self):
        self.is_connected = False
        self.current_hr = None
        
    async def connect(self, device_address: str):
        """Connect to BLE heart rate monitor."""
        # In production, use bleak library for BLE
        logger.info(f"Connecting to heart rate monitor: {device_address}")
        self.is_connected = True
        
    async def read_heart_rate(self) -> Optional[int]:
        """Read current heart rate."""
        if not self.is_connected:
            return None
        # In production, read from BLE characteristic
        import random
        return random.randint(65, 85)


class EnvironmentSensor:
    """Environmental sensors (temperature, humidity, motion)."""
    
    def __init__(self):
        self.temperature = None
        self.humidity = None
        self.motion_detected = False
        
    async def read_temperature(self) -> float:
        """Read room temperature."""
        # In production, read from DHT22 sensor via GPIO
        import random
        self.temperature = random.uniform(20, 25)
        return self.temperature
    
    async def read_humidity(self) -> float:
        """Read room humidity."""
        import random
        self.humidity = random.uniform(40, 60)
        return self.humidity
    
    async def check_motion(self) -> bool:
        """Check motion sensor."""
        # In production, read from PIR sensor via GPIO
        import random
        self.motion_detected = random.random() > 0.3
        return self.motion_detected


async def main():
    """Main entry point for IoT hub."""
    logger.info("Starting CARE-AI IoT Hub...")
    
    # Initialize sensors
    hub = SensorHub()
    hr_monitor = HeartRateMonitor()
    env_sensor = EnvironmentSensor()
    
    # Connect to devices
    await hr_monitor.connect("AA:BB:CC:DD:EE:FF")
    
    # Start collecting data
    try:
        await hub.start()
    except KeyboardInterrupt:
        await hub.stop()
        logger.info("IoT Hub shutdown complete")


if __name__ == "__main__":
    asyncio.run(main())
