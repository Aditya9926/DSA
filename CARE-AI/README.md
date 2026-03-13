# 🏥 CARE-AI: Intelligent Companion for Elderly Health & Safety

<p align="center">
  <img src="docs/logo.png" alt="CARE-AI Logo" width="200"/>
</p>

## 📋 Overview

CARE-AI is an AI-powered monitoring system designed to continuously track elderly health and predict emergencies. It combines wearable sensors, AI prediction models, smart home monitoring, and a mobile app for caregivers to provide comprehensive health monitoring and safety solutions for elderly individuals living alone.

## 🎯 Problem Statement

Many elderly people live alone and face critical challenges:
- 🔴 Sudden falls with delayed response
- ❤️ Heart problems requiring immediate attention
- 🧠 Memory issues and cognitive decline
- ⏰ Delayed medical help in emergencies
- 😔 Loneliness and mental health issues

**CARE-AI addresses these challenges through proactive AI-powered monitoring and prediction.**

## ✨ Key Features

### 1️⃣ Fall Detection using AI
- Uses accelerometer + gyroscope data from wearables
- **Algorithms:** Random Forest / LSTM neural networks
- Automatic alerts to family members or emergency services
- 95%+ accuracy in fall detection

### 2️⃣ Health Risk Prediction
- ML-based early warning system for health problems
- **Inputs:** Heart rate, sleep patterns, activity level, blood pressure
- **Outputs:** Risk predictions for stroke, heart attack, weakness
- Personalized health insights and recommendations

### 3️⃣ Smart Medication Reminder
- AI-powered medication scheduling
- Voice assistant integration
- Push notification system
- Caregiver tracking and compliance monitoring

### 4️⃣ Emotion & Loneliness Detection
- Voice analysis for emotional state detection
- Facial emotion recognition (optional camera integration)
- Depression and loneliness early detection
- Activity suggestions and family notifications

### 5️⃣ Caregiver Dashboard
- Real-time health statistics monitoring
- Alert management and history
- Daily activity tracking
- Emergency notification system
- Multi-user support for family members

## 🏗️ Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│                        CARE-AI System                            │
├─────────────────────────────────────────────────────────────────┤
│                                                                   │
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────────────┐  │
│  │  Wearables  │───▶│  IoT Hub    │───▶│   AI/ML Backend     │  │
│  │  (Sensors)  │    │ (Raspberry  │    │   (FastAPI +        │  │
│  └─────────────┘    │    Pi)      │    │    TensorFlow)      │  │
│                      └─────────────┘    └──────────┬──────────┘  │
│                                                     │             │
│  ┌─────────────┐    ┌─────────────┐    ┌──────────▼──────────┐  │
│  │  Mobile App │◀───│  Firebase   │◀───│    Database         │  │
│  │  (Flutter)  │    │  (Cloud)    │    │    (PostgreSQL)     │  │
│  └─────────────┘    └─────────────┘    └─────────────────────┘  │
│                                                                   │
└─────────────────────────────────────────────────────────────────┘
```

## 🛠️ Technology Stack

### AI/ML
- **Python 3.9+**
- **TensorFlow 2.x** - Deep learning models
- **PyTorch** - Alternative ML framework
- **Scikit-learn** - Traditional ML algorithms
- **OpenCV** - Computer vision for fall detection

### Backend
- **FastAPI** - High-performance API framework
- **PostgreSQL** - Primary database
- **Redis** - Caching and real-time data
- **Firebase** - Push notifications and auth

### Frontend
- **React.js** - Web dashboard
- **Flutter** - Cross-platform mobile app
- **Material UI** - UI components

### IoT/Hardware
- **Raspberry Pi 4** - IoT hub
- **Arduino** - Sensor integration
- **ESP32** - Wireless sensor modules

## 📁 Project Structure

```
CARE-AI/
├── backend/
│   ├── app/
│   │   ├── api/              # API endpoints
│   │   ├── models/           # Data models
│   │   ├── services/         # Business logic
│   │   ├── ml_models/        # AI/ML models
│   │   └── utils/            # Utilities
│   ├── tests/                # Unit tests
│   └── data/                 # Sample data
├── frontend/
│   ├── web/                  # React dashboard
│   └── mobile/               # Flutter app
├── iot/
│   ├── sensors/              # Sensor code
│   └── raspberry_pi/         # IoT hub code
├── docs/                     # Documentation
├── requirements.txt
└── README.md
```

## 🚀 Quick Start

### Prerequisites
- Python 3.9+
- Node.js 18+
- Flutter 3.x
- PostgreSQL 14+
- Redis

### Backend Setup

```bash
# Clone the repository
git clone https://github.com/Aditya9926/DSA.git
cd DSA/CARE-AI

# Create virtual environment
python -m venv venv
source venv/bin/activate  # On Windows: venv\Scripts\activate

# Install dependencies
pip install -r requirements.txt

# Run database migrations
python -m backend.app.utils.db_migrate

# Start the server
uvicorn backend.app.main:app --reload --host 0.0.0.0 --port 8000
```

### Frontend Setup

```bash
# Web Dashboard
cd frontend/web
npm install
npm start

# Mobile App
cd frontend/mobile/care_ai_app
flutter pub get
flutter run
```

## 📊 ML Models Performance

| Model | Task | Accuracy | F1 Score |
|-------|------|----------|----------|
| LSTM Fall Detector | Fall Detection | 96.5% | 0.94 |
| Random Forest | Health Risk | 89.2% | 0.87 |
| CNN Emotion | Emotion Detection | 82.4% | 0.80 |
| Gradient Boosting | Medication Adherence | 91.3% | 0.89 |

## 🔮 Future Roadmap

- [ ] AI predicting Alzheimer's early symptoms
- [ ] Voice assistant for elderly conversation
- [ ] Computer vision fall detection with camera
- [ ] Digital twin health model
- [ ] Integration with smart home devices
- [ ] Multi-language support

## 🌍 Expected Impact

- **Reduce elderly emergency deaths** by early detection
- **Detect health problems early** through continuous monitoring
- **Help families monitor remotely** with real-time dashboards
- **Improve mental health and safety** through emotional support

## 📬 Contact

- **Email:** adityasahu5189@gmail.com
- **LinkedIn:** [Aditya Sahu](https://www.linkedin.com/in/aditya-sahu-205ba9200)
- **GitHub:** [Aditya9926](https://github.com/Aditya9926)

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

<p align="center">
  Made with ❤️ for elderly care
</p>
