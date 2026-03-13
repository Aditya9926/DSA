import React from 'react';
import { Box, Typography, Card, CardContent, Grid } from '@mui/material';

function HealthMonitoring() {
  return (
    <Box>
      <Typography variant="h4" gutterBottom>
        Health Monitoring
      </Typography>
      <Typography variant="body1" color="text.secondary" sx={{ mb: 3 }}>
        Detailed health metrics and trends
      </Typography>
      
      <Grid container spacing={3}>
        <Grid item xs={12}>
          <Card>
            <CardContent>
              <Typography variant="h6">Vital Signs History</Typography>
              <Typography color="text.secondary">
                Monitor blood pressure, heart rate, oxygen levels, and more.
              </Typography>
            </CardContent>
          </Card>
        </Grid>
        <Grid item xs={12} md={6}>
          <Card>
            <CardContent>
              <Typography variant="h6">Blood Pressure Trends</Typography>
              <Typography>Average: 125/80 mmHg</Typography>
              <Typography color="success.main">Status: Normal</Typography>
            </CardContent>
          </Card>
        </Grid>
        <Grid item xs={12} md={6}>
          <Card>
            <CardContent>
              <Typography variant="h6">Sleep Analysis</Typography>
              <Typography>Average: 7.2 hours/night</Typography>
              <Typography color="success.main">Quality: Good</Typography>
            </CardContent>
          </Card>
        </Grid>
      </Grid>
    </Box>
  );
}

export default HealthMonitoring;
