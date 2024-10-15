#!/bin/bash

# Usage:
# source ./my_script.sh
# quit env with cmd: deactivate

venv_path="./django_venv"

# Setup python dev environement
# -m : allow module to run in isolation
python3 -m venv $venv_path

# Activate python env
source $venv_path/bin/activate

# Pip upgrade
echo "=============={🧰 Pip Upgrade 🧰}=============="
pip install --upgrade pip

# Installation
# --upgrade: enforce replacement of package already installed
echo "=============={🧰 Path Module Installation 🧰}=============="
pip install -r requirement.txt

