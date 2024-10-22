#!/bin/bash

# Usage:
# source ./my_script.sh <env|django|help>
# quit env with cmd: deactivate

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
RESET='\033[0m'

venv_path=".venv"
project_name="d06"

# Function to display help message
show_help() {
  echo -e "${CYAN}Usage:${RESET}"
  echo -e "${GREEN}  source ./my_script.sh <launch|env|django|help>${RESET}"
  echo -e "${CYAN}Commands:${RESET}"
  echo -e "${YELLOW}  launch${RESET}   : Setup Python env and Run Django project"
  echo -e "${YELLOW}  env${RESET}      : Setup Python environment (install virtualenv, dependencies)"
  echo -e "${YELLOW}  django${RESET}   : Run the Django project (migrate, collectstatic, runserver)"
  echo -e "${YELLOW}  help${RESET}     : Display this help message"
}

# Function to setup Python environment
setup_env() {
  echo "Setting up Python environment..."
  python3 -m venv $venv_path
  source $venv_path/bin/activate
  
  echo "=============={🧰 ${CYAN}Pip Upgrade${RESET} 🧰}=============="
  pip install --upgrade pip

  echo "=============={🧰 ${CYAN}Path Module Installation${RESET} 🧰}=============="
  pip install --upgrade -r requirements.txt
}

# Function to run the Django project
run_django() {
  echo "=============={🚀 ${CYAN}Program Launch${RESET} 🚀}=============="
  cd $project_name
  python3 manage.py makemigration
  python3 manage.py migrate
  python3 manage.py collectstatic --no-input
  python3 manage.py runserver
}

# Handle script arguments
case "$1" in
  launch)
    setup_env
    run_django
    ;;
  env)
    setup_env
    ;;
  django)
    run_django
    ;;
  help)
    show_help
    ;;
  *)
    echo -e "${RED}Invalid option! Use 'help' for usage information.${RESET}"
    ;;
esac
