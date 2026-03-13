import React from 'react';
import { Box, Typography, Card, CardContent, Grid, List, ListItem, ListItemIcon, ListItemText, Chip } from '@mui/material';
import { Warning, CheckCircle, Info } from '@mui/icons-material';

function Alerts() {
  const alerts = [
    { type: 'warning', title: 'Low activity detected', time: '2 hours ago', status: 'active' },
    { type: 'success', title: 'Morning medication taken', time: '8:05 AM', status: 'resolved' },
    { type: 'info', title: 'Daily check-in reminder sent', time: 'Yesterday', status: 'resolved' },
    { type: 'success', title: 'Fall detection system active', time: '2 days ago', status: 'resolved' },
  ];

  const getIcon = (type) => {
    switch (type) {
      case 'warning': return <Warning color="warning" />;
      case 'success': return <CheckCircle color="success" />;
      default: return <Info color="info" />;
    }
  };

  return (
    <Box>
      <Typography variant="h4" gutterBottom>
        Alerts & Notifications
      </Typography>
      <Typography variant="body1" color="text.secondary" sx={{ mb: 3 }}>
        View and manage all alerts
      </Typography>
      
      <Grid container spacing={3}>
        <Grid item xs={12}>
          <Card>
            <CardContent>
              <Typography variant="h6" gutterBottom>Recent Alerts</Typography>
              <List>
                {alerts.map((alert, index) => (
                  <ListItem key={index} divider={index < alerts.length - 1}>
                    <ListItemIcon>
                      {getIcon(alert.type)}
                    </ListItemIcon>
                    <ListItemText 
                      primary={alert.title}
                      secondary={alert.time}
                    />
                    <Chip 
                      label={alert.status}
                      size="small"
                      color={alert.status === 'active' ? 'warning' : 'default'}
                    />
                  </ListItem>
                ))}
              </List>
            </CardContent>
          </Card>
        </Grid>
      </Grid>
    </Box>
  );
}

export default Alerts;
