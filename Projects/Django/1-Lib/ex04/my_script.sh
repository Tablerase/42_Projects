#!/bin/bash

# To install Path: https://pypi.org/project/path/
#                  https://github.com/jaraco/path
# Pip Install: https://pip.pypa.io/en/stable/cli/pip_install/

log_file="install.log"
git_repo="https://github.com/jaraco/path.git"
venv_path="./django_venv"

# Setup python dev environement
# -m : allow module to run in isolation
python3 -m venv $venv_path
source $venv_path/bin/activate

# Display PIP version
echo "=============={🧰 PIP Version 🧰}=============="
python3 -m pip --version

# Installation
# --report : log the Installation
# --target : send installed package to folder
# --upgrade: enforce replacement of package already installed
echo "=============={🧰 Path Module Installation 🧰}=============="
python3 -m pip install git+$git_repo --report=$log_file --upgrade

