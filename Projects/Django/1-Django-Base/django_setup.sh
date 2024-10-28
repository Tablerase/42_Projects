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
pip install --upgrade -r requirements.txt

# Run program
# echo "=============={🚀 Program Launch 🚀}=============="
# cd hello_project
# python3 manage.py migrate
# python3 manage.py collectstatic --no-input
# python3 manage.py runserver
