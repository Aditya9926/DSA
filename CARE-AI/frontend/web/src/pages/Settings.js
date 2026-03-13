import React from 'react';
import { Box, Typography, Card, CardContent, Grid, Switch, FormControlLabel } from '@mui/material';

function Settings() {
  return (
    <Box>
      <Typography variant="h4" gutterBottom>
        Settings
      </Typography>
      <Typography variant="body1" color="text.secondary" sx={{ mb: 3 }}>
        Configure notifications and preferences
      </Typography>
      
      <Grid container spacing={3}>
        <Grid item xs={12} md={6}>
          <Card>
            <CardContent>
              <Typography variant="h6" gutterBottom>Notification Settings</Typography>
              <FormControlLabel 
                control={<Switch defaultChecked />} 
                label="Push Notifications"
              />
              <br />
              <FormControlLabel 
                control={<Switch defaultChecked />} 
                label="SMS Alerts"
              />
              <br />
              <FormControlLabel 
                control={<Switch defaultChecked />} 
                label="Email Notifications"
              />
              <br />
              <FormControlLabel 
                control={<Switch defaultChecked />} 
                label="Emergency Call on Critical Alert"
              />
            </CardContent>
          </Card>
        </Grid>
        <Grid item xs={12} md={6}>
          <Card>
            <CardContent>
              <Typography variant="h6" gutterBottom>Alert Thresholds</Typography>
              <Typography>Fall Detection Sensitivity: High</Typography>
              <Typography>Inactivity Alert: After 3 hours</Typography>
              <Typography>Medication Reminder: 15 min before</Typography>
            </CardContent>
          </Card>
        </Grid>
      </Grid>
    </Box>
  );
}

export default Settings;
