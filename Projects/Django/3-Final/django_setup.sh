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
project_name="d09"
database_folder="$project_name/db.sqlite3"
fixtures_path="fixtures/"
declare -a fixtures=(
  "$fixtures_path/chatrooms.json"
  "$fixtures_path/users.json"
)

# Function to display help message
show_help() {
  echo -e "${CYAN}Usage:${RESET}"
  echo -e "${GREEN}  source ./my_script.sh <launch|env|django|help>${RESET}"
  echo -e "${CYAN}Commands:${RESET}"
  echo -e "${YELLOW}  launch${RESET}       : Setup Python env and Run Django project"
  echo -e "${YELLOW}  env${RESET}          : Setup Python environment (install virtualenv, dependencies)"
  echo -e "${YELLOW}  django${RESET}       : Run the Django project (migrate, collectstatic, runserver)"
  echo -e "${YELLOW}  load_fixtures${RESET}: Load initial data into the database"
  echo -e "${YELLOW}  run_docker${RESET}   : Setup Docker containers"
  echo -e "${YELLOW}  stop_docker${RESET}  : Stop Docker containers"
  echo -e "${YELLOW}  clean${RESET}        : Remove every data, env"
  echo -e "${YELLOW}  db_shell${RESET}     : Access the database shell"
  echo -e "${YELLOW}  superuser${RESET}    : Create a superuser"
  echo -e "${YELLOW}  help${RESET}         : Display this help message"
}

# Function to setup Python environment
setup_env() {
  echo "Setting up Python environment..."
  python3 -m venv $venv_path
  source $venv_path/bin/activate

  echo -e "=============={🧰 ${CYAN}Pip Upgrade${RESET} 🧰}=============="
  pip install --upgrade pip

  echo -e "=============={🧰 ${CYAN}Path Module Installation${RESET} 🧰}=============="
  pip install --upgrade -r requirements.txt
}

# Function to run the Django project
run_django() {
  echo -e "=============={🚀 ${CYAN}Program Launch${RESET} 🚀}=============="
  cd $project_name
  python3 manage.py makemigrations
  python3 manage.py migrate
  python3 manage.py collectstatic --no-input
  python3 manage.py runserver
}

# Function to setup Docker containers
run_docker() {
  echo -e "=============={🐳 ${CYAN}Containers Launch${RESET} 🐳}=============="
  docker compose up -d
  if [ $? -eq 0 ]; then
    echo -e "${GREEN}Docker containers launched successfully.${RESET}"
  else
    echo -e "${RED}Failed to launch Docker containers.${RESET}"
    exit 1
  fi
}

# Function to stop Docker containers
stop_docker() {
  echo -e "=============={🛑 ${CYAN}Containers Stop${RESET} 🛑}=============="
  docker compose down
  if [ $? -eq 0 ]; then
    echo -e "${GREEN}Docker containers stopped successfully.${RESET}"
  else
    echo -e "${RED}Failed to stop Docker containers.${RESET}"
    exit 1
  fi
}

# Function to clean up the program env
cleanup() {
  echo -e "=============={🧹 ${CYAN}Cleaning Up${RESET} 🧹}=============="

  # Remove Database
  if [ -d "$database_folder" ]; then
    rm -rf $database_folder
    if [ $? -eq 0 ]; then
      echo -e "${GREEN}Database folder removed successfully.${RESET}"
    else
      echo -e "${RED}Failed to remove Database folder.${RESET}"
    fi
  else
    echo -e "${YELLOW}No Database folder found.${RESET}"
  fi

  # Deactivate and remove Python virtual environment
  if [ -d "$venv_path" ]; then
    rm -rf $venv_path
    if [ $? -eq 0 ]; then
      echo -e "${GREEN}Python virtual environment removed successfully.${RESET}"
    else
      echo -e "${RED}Failed to remove Python virtual environment.${RESET}"
    fi
  else
    echo -e "${YELLOW}No Python virtual environment found.${RESET}"
  fi
}

# Function to load the initial data into the database
load_fixtures() {
  echo -e "=============={📥 ${CYAN}Loading Data${RESET} 📥}=============="
  cd $project_name
  python3 manage.py migrate
  for fixture in "${fixtures[@]}"; do
    if [ ! -f "$fixture" ]; then
      echo -e "${RED}Fixture file not found: $fixture${RESET}"
      exit 1
    fi
    python3 manage.py loaddata $fixture
  done
}

# Function to access the database shell
db_shell() {
  echo -e "=============={🐚 ${CYAN}Database Shell${RESET} 🐚}=============="
  cd $project_name
  python3 manage.py dbshell
}

# Function to create a superuser
superuser() {
  echo -e "=============={🦸 ${CYAN}Superuser Creation${RESET} 🦸}=============="
  cd $project_name
  python3 manage.py createsuperuser
}

# Handle script arguments
case "$1" in
launch)
  setup_env
  run_docker
  run_django
  ;;
env)
  setup_env
  ;;
django)
  run_django
  ;;
run_docker)
  run_docker
  ;;
stop_docker)
  stop_docker
  ;;
superuser)
  superuser
  ;;
load_fixtures)
  load_fixtures
  ;;
clean)
  cleanup
  ;;
help)
  show_help
  ;;
db_shell)
  db_shell
  ;;
*)
  echo -e "${RED}Invalid option! Use 'help' for usage information.${RESET}"
  ;;
esac
