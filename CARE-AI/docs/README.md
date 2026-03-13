# CARE-AI Documentation

## Table of Contents

1. [Getting Started](#getting-started)
2. [System Architecture](#system-architecture)
3. [API Documentation](#api-documentation)
4. [ML Models](#ml-models)
5. [Deployment Guide](#deployment-guide)

## Getting Started

### Prerequisites

- Python 3.9+
- Node.js 18+
- Flutter 3.x
- PostgreSQL 14+
- Redis 7+

### Quick Start

```bash
# Clone repository
git clone https://github.com/Aditya9926/DSA.git
cd DSA/CARE-AI

# Backend setup
python -m venv venv
source venv/bin/activate
pip install -r requirements.txt
uvicorn backend.app.main:app --reload

# Frontend setup (new terminal)
cd frontend/web
npm install
npm start
```

## System Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                     CARE-AI Architecture                     │
├─────────────────────────────────────────────────────────────┤
│                                                              │
│  ┌──────────────┐     ┌──────────────┐     ┌─────────────┐ │
│  │   Wearable   │────▶│   IoT Hub    │────▶│   Backend   │ │
│  │   Devices    │     │ (Raspberry   │     │  (FastAPI)  │ │
│  └──────────────┘     │     Pi)      │     └─────┬───────┘ │
│                       └──────────────┘           │         │
│                                                  ▼         │
│  ┌──────────────┐     ┌──────────────┐     ┌─────────────┐ │
│  │  Mobile App  │◀───▶│   Firebase   │◀───▶│  Database   │ │
│  │  (Flutter)   │     │    Cloud     │     │ (PostgreSQL)│ │
│  └──────────────┘     └──────────────┘     └─────────────┘ │
│                                                              │
│  ┌──────────────┐     ┌──────────────┐                     │
│  │  Web Dashboard│◀───│  ML Models   │                     │
│  │   (React)    │     │ (TensorFlow) │                     │
│  └──────────────┘     └──────────────┘                     │
│                                                              │
└─────────────────────────────────────────────────────────────┘
```

## API Documentation

### Base URL
```
http://localhost:8000/api/v1
```

### Endpoints

#### Health Check
- `GET /health` - System health status

#### Fall Detection
- `POST /fall-detection/analyze` - Analyze sensor data for falls
- `GET /fall-detection/alerts/{user_id}` - Get fall alerts
- `GET /fall-detection/statistics/{user_id}` - Get fall statistics

#### Health Prediction
- `POST /health-prediction/predict` - Predict health risks
- `POST /health-prediction/analyze-vitals` - Quick vital signs analysis
- `GET /health-prediction/trends/{user_id}` - Get health trends

#### Medication
- `POST /medication/schedule` - Create medication schedule
- `GET /medication/schedule/{user_id}` - Get medication schedule
- `POST /medication/log` - Log medication intake
- `GET /medication/adherence/{user_id}` - Get adherence stats

#### Emotion Detection
- `POST /emotion/analyze-voice` - Analyze voice for emotion
- `POST /emotion/mood-checkin` - Submit mood check-in
- `GET /emotion/recommendations/{user_id}` - Get wellness recommendations

#### Alerts
- `POST /alerts/create` - Create new alert
- `GET /alerts/user/{user_id}` - Get user alerts
- `POST /alerts/sos/{user_id}` - Trigger SOS emergency

## ML Models

### Fall Detection (LSTM)
- **Input**: 50 timesteps × 6 features (accelerometer + gyroscope)
- **Output**: Binary classification (fall/no-fall)
- **Accuracy**: 96.5%

### Health Risk Prediction (Random Forest)
- **Input**: Vital signs + health history
- **Output**: Risk scores for cardiovascular, stroke, weakness
- **Accuracy**: 89.2%

### Emotion Detection (CNN)
- **Input**: Facial images or voice recordings
- **Output**: 7 emotion classifications
- **Accuracy**: 82.4%

## Deployment Guide

### Docker Deployment

```yaml
# docker-compose.yml
version: '3.8'
services:
  backend:
    build: ./backend
    ports:
      - "8000:8000"
    environment:
      - DATABASE_URL=postgresql://user:pass@db:5432/careai
    
  frontend:
    build: ./frontend/web
    ports:
      - "3000:3000"
    
  db:
    image: postgres:14
    environment:
      - POSTGRES_USER=user
      - POSTGRES_PASSWORD=pass
      - POSTGRES_DB=careai
```

### Production Considerations

1. **Security**: Enable HTTPS, implement rate limiting
2. **Scalability**: Use load balancer, container orchestration
3. **Monitoring**: Set up logging, metrics, and alerting
4. **Backup**: Regular database backups
5. **Compliance**: HIPAA compliance for health data

## License

MIT License - See LICENSE file for details.
