#!/bin/sh

# Recover the first argument
arg=$1

# Command allowed: curl, grep, cut
## Curl (Client URL)
# -s: silent - hide progress bar
# -I: include header - only header will be displayed (no body)

## Grep (Global Regular Expression Print)
# Regular expression: Location

## Cut (Cut out selected portions of each line of a file)
# -d: delimiter - here it is space
# -f: field - here it is 2 (second field)

# Get full URL from bit.ly URL
curl -sI $arg | grep Location | cut -d ' ' -f 2