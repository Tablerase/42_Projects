#!/bin/bash

# Try to auto-detect touchpad ID if not set
if [ -z "$DEVICE" ]; then
    DEVICE=$(xinput list | grep -i 'touchpad' | awk -F'=' '{print $2}' | awk '{print $1}')
fi

# Check if DEVICE is still empty
if [ -z "$DEVICE" ]; then
    echo "Unable to detect touchpad device. Please set DEVICE manually."
    exit 1
fi

STATUS=$(xinput list-props $DEVICE | grep "Device Enabled" | awk '{print $4}')

if [ "$STATUS" == "1" ]; then
    xinput disable $DEVICE
else
    xinput enable $DEVICE
fi