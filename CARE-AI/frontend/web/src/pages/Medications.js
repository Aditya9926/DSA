import React from 'react';
import { Box, Typography, Card, CardContent, Grid, List, ListItem, ListItemText, Chip } from '@mui/material';

function Medications() {
  const medications = [
    { name: 'Metformin', dosage: '500mg', frequency: 'Twice daily', adherence: 92 },
    { name: 'Lisinopril', dosage: '10mg', frequency: 'Once daily', adherence: 88 },
    { name: 'Aspirin', dosage: '81mg', frequency: 'Once daily', adherence: 95 },
  ];

  return (
    <Box>
      <Typography variant="h4" gutterBottom>
        Medication Management
      </Typography>
      <Typography variant="body1" color="text.secondary" sx={{ mb: 3 }}>
        Track medications and adherence
      </Typography>
      
      <Grid container spacing={3}>
        <Grid item xs={12} md={8}>
          <Card>
            <CardContent>
              <Typography variant="h6" gutterBottom>Current Medications</Typography>
              <List>
                {medications.map((med, index) => (
                  <ListItem key={index} divider={index < medications.length - 1}>
                    <ListItemText 
                      primary={`${med.name} - ${med.dosage}`}
                      secondary={med.frequency}
                    />
                    <Chip 
                      label={`${med.adherence}% adherence`}
                      color={med.adherence >= 90 ? 'success' : 'warning'}
                    />
                  </ListItem>
                ))}
              </List>
            </CardContent>
          </Card>
        </Grid>
        <Grid item xs={12} md={4}>
          <Card>
            <CardContent>
              <Typography variant="h6">Overall Adherence</Typography>
              <Typography variant="h2" color="success.main" sx={{ my: 2 }}>
                89%
              </Typography>
              <Typography color="text.secondary">
                Last 30 days average
              </Typography>
            </CardContent>
          </Card>
        </Grid>
      </Grid>
    </Box>
  );
}

export default Medications;
