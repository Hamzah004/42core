#!/bin/bash

echo "Starting up the server setup..."
sleep 0.5
echo "log in into the root user..."
sleep 0.5
echo "Enter root user password:"
su -
echo "Installing sudo command:"
apt install sudo -y
echo ""
echo "setting up ssh..."
