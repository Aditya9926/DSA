import React from 'react';
import { useNavigate, useLocation } from 'react-router-dom';
import {
  Drawer,
  List,
  ListItem,
  ListItemButton,
  ListItemIcon,
  ListItemText,
  Divider,
  Box,
  Typography,
} from '@mui/material';
import {
  Dashboard as DashboardIcon,
  Favorite as HealthIcon,
  Medication as MedicationIcon,
  Warning as AlertIcon,
  Settings as SettingsIcon,
  Person as PersonIcon,
} from '@mui/icons-material';

const drawerWidth = 240;

const menuItems = [
  { text: 'Dashboard', icon: <DashboardIcon />, path: '/' },
  { text: 'Health Monitoring', icon: <HealthIcon />, path: '/health' },
  { text: 'Medications', icon: <MedicationIcon />, path: '/medications' },
  { text: 'Alerts', icon: <AlertIcon />, path: '/alerts' },
  { text: 'Settings', icon: <SettingsIcon />, path: '/settings' },
];

function Sidebar({ open }) {
  const navigate = useNavigate();
  const location = useLocation();

  return (
    <Drawer
      variant="persistent"
      anchor="left"
      open={open}
      sx={{
        width: drawerWidth,
        flexShrink: 0,
        '& .MuiDrawer-paper': {
          width: drawerWidth,
          boxSizing: 'border-box',
          top: '64px',
          height: 'calc(100% - 64px)',
        },
      }}
    >
      {/* User Info */}
      <Box sx={{ p: 2, textAlign: 'center', bgcolor: 'primary.light', color: 'white' }}>
        <PersonIcon sx={{ fontSize: 48 }} />
        <Typography variant="subtitle1">
          Monitoring: Robert Johnson
        </Typography>
        <Typography variant="caption" sx={{ opacity: 0.8 }}>
          Status: All Good ✓
        </Typography>
      </Box>

      <Divider />

      {/* Navigation Menu */}
      <List>
        {menuItems.map((item) => (
          <ListItem key={item.text} disablePadding>
            <ListItemButton
              selected={location.pathname === item.path}
              onClick={() => navigate(item.path)}
              sx={{
                '&.Mui-selected': {
                  bgcolor: 'primary.light',
                  color: 'white',
                  '& .MuiListItemIcon-root': {
                    color: 'white',
                  },
                },
                '&.Mui-selected:hover': {
                  bgcolor: 'primary.main',
                },
              }}
            >
              <ListItemIcon>{item.icon}</ListItemIcon>
              <ListItemText primary={item.text} />
            </ListItemButton>
          </ListItem>
        ))}
      </List>

      <Divider />

      {/* Quick Stats */}
      <Box sx={{ p: 2 }}>
        <Typography variant="subtitle2" color="text.secondary" gutterBottom>
          Today's Summary
        </Typography>
        <Typography variant="body2">
          ❤️ Heart Rate: 72 BPM
        </Typography>
        <Typography variant="body2">
          🚶 Steps: 2,500
        </Typography>
        <Typography variant="body2">
          💊 Medications: 2/3
        </Typography>
        <Typography variant="body2">
          😊 Mood: Good
        </Typography>
      </Box>
    </Drawer>
  );
}

export default Sidebar;
