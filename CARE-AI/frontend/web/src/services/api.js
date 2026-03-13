import axios from 'axios';

const API_BASE_URL = process.env.REACT_APP_API_URL || 'http://localhost:8000/api/v1';

const api = axios.create({
  baseURL: API_BASE_URL,
  headers: {
    'Content-Type': 'application/json',
  },
});

// Health Monitoring API
export const healthApi = {
  getVitals: (userId) => api.get(`/health-prediction/trends/${userId}?metric=heart_rate`),
  predictRisks: (data) => api.post('/health-prediction/predict', data),
  analyzeVitals: (userId, vitals) => api.post(`/health-prediction/analyze-vitals?user_id=${userId}`, vitals),
};

// Fall Detection API
export const fallDetectionApi = {
  getAlerts: (userId) => api.get(`/fall-detection/alerts/${userId}`),
  getStatistics: (userId, days = 30) => api.get(`/fall-detection/statistics/${userId}?days=${days}`),
};

// Medication API
export const medicationApi = {
  getSchedule: (userId) => api.get(`/medication/schedule/${userId}`),
  getToday: (userId) => api.get(`/medication/today/${userId}`),
  logIntake: (data) => api.post('/medication/log', data),
  getAdherence: (userId, days = 30) => api.get(`/medication/adherence/${userId}?days=${days}`),
};

// Alerts API
export const alertsApi = {
  getAlerts: (userId) => api.get(`/alerts/user/${userId}`),
  acknowledgeAlert: (alertId, responderId) => 
    api.post(`/alerts/acknowledge/${alertId}?responder_id=${responderId}`),
  triggerSOS: (userId) => api.post(`/alerts/sos/${userId}`),
};

// User API
export const userApi = {
  getProfile: (userId) => api.get(`/users/${userId}`),
  updateProfile: (userId, data) => api.put(`/users/${userId}`, data),
  getCaregiverDashboard: (caregiverId) => api.get(`/users/dashboard/${caregiverId}`),
};

// Emotion API
export const emotionApi = {
  getMoodHistory: (userId, days = 30) => api.get(`/emotion/mood-history/${userId}?days=${days}`),
  getRecommendations: (userId) => api.get(`/emotion/recommendations/${userId}`),
  submitMoodCheckin: (data) => api.post('/emotion/mood-checkin', data),
};

export default api;
