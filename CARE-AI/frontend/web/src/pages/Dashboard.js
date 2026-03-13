import React from 'react';
import {
  Grid,
  Card,
  CardContent,
  Typography,
  Box,
  Chip,
  Avatar,
  LinearProgress,
  Paper,
} from '@mui/material';
import {
  Favorite as HeartIcon,
  DirectionsWalk as WalkIcon,
  Bedtime as SleepIcon,
  Medication as MedicationIcon,
  Warning as WarningIcon,
  CheckCircle as CheckIcon,
} from '@mui/icons-material';
import {
  LineChart,
  Line,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  ResponsiveContainer,
  AreaChart,
  Area,
} from 'recharts';

// Sample data for charts
const heartRateData = [
  { time: '6AM', rate: 68 },
  { time: '8AM', rate: 72 },
  { time: '10AM', rate: 78 },
  { time: '12PM', rate: 75 },
  { time: '2PM', rate: 71 },
  { time: '4PM', rate: 74 },
  { time: '6PM', rate: 70 },
];

const activityData = [
  { day: 'Mon', steps: 3200 },
  { day: 'Tue', steps: 4100 },
  { day: 'Wed', steps: 2800 },
  { day: 'Thu', steps: 3500 },
  { day: 'Fri', steps: 4200 },
  { day: 'Sat', steps: 3800 },
  { day: 'Sun', steps: 2500 },
];

// Stat Card Component
function StatCard({ title, value, unit, icon, color, trend }) {
  return (
    <Card>
      <CardContent>
        <Box sx={{ display: 'flex', alignItems: 'center', justifyContent: 'space-between' }}>
          <Box>
            <Typography color="text.secondary" variant="body2" gutterBottom>
              {title}
            </Typography>
            <Typography variant="h4" component="div" sx={{ fontWeight: 'bold' }}>
              {value}
              <Typography component="span" variant="body1" color="text.secondary">
                {' '}{unit}
              </Typography>
            </Typography>
            {trend && (
              <Chip 
                label={trend} 
                size="small" 
                color={trend.includes('+') ? 'success' : 'default'} 
                sx={{ mt: 1 }}
              />
            )}
          </Box>
          <Avatar sx={{ bgcolor: color, width: 56, height: 56 }}>
            {icon}
          </Avatar>
        </Box>
      </CardContent>
    </Card>
  );
}

// Alert Card Component
function AlertCard({ alerts }) {
  return (
    <Card>
      <CardContent>
        <Typography variant="h6" gutterBottom>
          Recent Alerts
        </Typography>
        {alerts.map((alert, index) => (
          <Paper 
            key={index} 
            elevation={0} 
            sx={{ 
              p: 1.5, 
              mb: 1, 
              bgcolor: alert.severity === 'warning' ? 'warning.light' : 'success.light',
              borderRadius: 2,
            }}
          >
            <Box sx={{ display: 'flex', alignItems: 'center', gap: 1 }}>
              {alert.severity === 'warning' ? (
                <WarningIcon color="warning" />
              ) : (
                <CheckIcon color="success" />
              )}
              <Box>
                <Typography variant="body2" fontWeight="medium">
                  {alert.title}
                </Typography>
                <Typography variant="caption" color="text.secondary">
                  {alert.time}
                </Typography>
              </Box>
            </Box>
          </Paper>
        ))}
      </CardContent>
    </Card>
  );
}

// Medication Card Component
function MedicationCard({ medications }) {
  return (
    <Card>
      <CardContent>
        <Typography variant="h6" gutterBottom>
          Today's Medications
        </Typography>
        <Box sx={{ mb: 2 }}>
          <Typography variant="body2" color="text.secondary">
            Progress: 2 of 3 taken
          </Typography>
          <LinearProgress variant="determinate" value={67} sx={{ mt: 1, height: 8, borderRadius: 4 }} />
        </Box>
        {medications.map((med, index) => (
          <Box 
            key={index} 
            sx={{ 
              display: 'flex', 
              alignItems: 'center', 
              justifyContent: 'space-between',
              py: 1,
              borderBottom: index < medications.length - 1 ? 1 : 0,
              borderColor: 'divider',
            }}
          >
            <Box sx={{ display: 'flex', alignItems: 'center', gap: 1 }}>
              <MedicationIcon color={med.taken ? 'success' : 'action'} />
              <Box>
                <Typography variant="body2">{med.name}</Typography>
                <Typography variant="caption" color="text.secondary">
                  {med.dosage} - {med.time}
                </Typography>
              </Box>
            </Box>
            <Chip 
              label={med.taken ? 'Taken' : 'Pending'} 
              size="small" 
              color={med.taken ? 'success' : 'default'}
            />
          </Box>
        ))}
      </CardContent>
    </Card>
  );
}

function Dashboard() {
  const alerts = [
    { title: 'Morning medication taken', time: '8:05 AM', severity: 'success' },
    { title: 'Low activity detected', time: '2:30 PM', severity: 'warning' },
    { title: 'Daily check-in completed', time: '9:00 AM', severity: 'success' },
  ];

  const medications = [
    { name: 'Metformin', dosage: '500mg', time: '8:00 AM', taken: true },
    { name: 'Lisinopril', dosage: '10mg', time: '8:00 AM', taken: true },
    { name: 'Metformin', dosage: '500mg', time: '8:00 PM', taken: false },
  ];

  return (
    <Box>
      <Typography variant="h4" gutterBottom>
        Health Dashboard
      </Typography>
      <Typography variant="body1" color="text.secondary" sx={{ mb: 3 }}>
        Real-time monitoring for Robert Johnson
      </Typography>

      {/* Stats Row */}
      <Grid container spacing={3} sx={{ mb: 3 }}>
        <Grid item xs={12} sm={6} md={3}>
          <StatCard 
            title="Heart Rate" 
            value={72} 
            unit="BPM" 
            icon={<HeartIcon />} 
            color="#e91e63"
            trend="Normal"
          />
        </Grid>
        <Grid item xs={12} sm={6} md={3}>
          <StatCard 
            title="Steps Today" 
            value="2,500" 
            unit="" 
            icon={<WalkIcon />} 
            color="#2196f3"
            trend="+15%"
          />
        </Grid>
        <Grid item xs={12} sm={6} md={3}>
          <StatCard 
            title="Sleep Last Night" 
            value="7.5" 
            unit="hrs" 
            icon={<SleepIcon />} 
            color="#9c27b0"
            trend="Good"
          />
        </Grid>
        <Grid item xs={12} sm={6} md={3}>
          <StatCard 
            title="Health Score" 
            value={78} 
            unit="/100" 
            icon={<CheckIcon />} 
            color="#4caf50"
            trend="Stable"
          />
        </Grid>
      </Grid>

      {/* Charts Row */}
      <Grid container spacing={3} sx={{ mb: 3 }}>
        <Grid item xs={12} md={8}>
          <Card>
            <CardContent>
              <Typography variant="h6" gutterBottom>
                Heart Rate Today
              </Typography>
              <ResponsiveContainer width="100%" height={300}>
                <LineChart data={heartRateData}>
                  <CartesianGrid strokeDasharray="3 3" />
                  <XAxis dataKey="time" />
                  <YAxis domain={[60, 90]} />
                  <Tooltip />
                  <Line 
                    type="monotone" 
                    dataKey="rate" 
                    stroke="#e91e63" 
                    strokeWidth={2}
                    dot={{ fill: '#e91e63' }}
                  />
                </LineChart>
              </ResponsiveContainer>
            </CardContent>
          </Card>
        </Grid>
        <Grid item xs={12} md={4}>
          <AlertCard alerts={alerts} />
        </Grid>
      </Grid>

      {/* Activity and Medications Row */}
      <Grid container spacing={3}>
        <Grid item xs={12} md={8}>
          <Card>
            <CardContent>
              <Typography variant="h6" gutterBottom>
                Weekly Activity
              </Typography>
              <ResponsiveContainer width="100%" height={300}>
                <AreaChart data={activityData}>
                  <CartesianGrid strokeDasharray="3 3" />
                  <XAxis dataKey="day" />
                  <YAxis />
                  <Tooltip />
                  <Area 
                    type="monotone" 
                    dataKey="steps" 
                    stroke="#2196f3" 
                    fill="#bbdefb"
                  />
                </AreaChart>
              </ResponsiveContainer>
            </CardContent>
          </Card>
        </Grid>
        <Grid item xs={12} md={4}>
          <MedicationCard medications={medications} />
        </Grid>
      </Grid>
    </Box>
  );
}

export default Dashboard;
