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
database_folder="./db"

# Function to display help message
show_help() {
  echo -e "${CYAN}Usage:${RESET}"
  echo -e "${GREEN}  source ./my_script.sh <launch|env|django|help>${RESET}"
  echo -e "${CYAN}Commands:${RESET}"
  echo -e "${YELLOW}  launch${RESET}   : Setup Docker containers, Python env and Run Django project"
  echo -e "${YELLOW}  env${RESET}      : Setup Python environment (install virtualenv, dependencies)"
  echo -e "${YELLOW}  django${RESET}   : Run the Django project (migrate, collectstatic, runserver)"
  echo -e "${YELLOW}  data${RESET}     : Load data (exercices_data) into the django database"
  echo -e "${YELLOW}  docker${RESET}   : Setup Docker containers (postgresql and adminer)"
  echo -e "${YELLOW}  clean${RESET}    : Remove every containers, images, volumes, data, env"
  echo -e "${YELLOW}  help${RESET}     : Display this help message"
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
run_docker(){
    echo -e "=============={🐳 ${CYAN}Containers Launch${RESET} 🐳}=============="
    mkdir -p $database_folder
    docker compose up -d
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Docker containers launched successfully.${RESET}"
    else
        echo -e "${RED}Failed to launch Docker containers.${RESET}"
        exit 1
    fi
}

# Load data into Django Database
load_data() {
   echo -e "=============={🧮 ${CYAN}Load Data${RESET} 🧮}=============="
   cd $project_name
   python3 manage.py loaddata "$project_name/exercices_data/ex09_initial_data.json" > /dev/null 2>&1
   # python3 manage.py loaddata "$project_name/exercices_data/ex10_initial_data.json"
}

# Function to clean up the program env
cleanup() {
    echo -e "=============={🧹 ${CYAN}Cleaning Up${RESET} 🧹}=============="
    
    # Stop and remove Docker containers
    docker compose down
    if [ $? -eq 0 ]; then
            echo -e "${GREEN}Docker containers stopped and removed successfully.${RESET}"
    else
            echo -e "${RED}Failed to stop and remove Docker containers.${RESET}"
    fi

    # Remove Docker images
    docker rmi $(docker images -q)
    if [ $? -eq 0 ]; then
            echo -e "${GREEN}Docker images removed successfully.${RESET}"
    else
            echo -e "${RED}Failed to remove Docker images.${RESET}"
    fi

    # Remove Docker volumes
    docker volume prune -f
    if [ $? -eq 0 ]; then
            echo -e "${GREEN}Docker volumes removed successfully.${RESET}"
    else
            echo -e "${RED}Failed to remove Docker volumes.${RESET}"
    fi
    # Remove Database
    if [ -d  "$database_folder" ]; then
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

# Handle script arguments
case "$1" in
  launch)
    run_docker
    setup_env
    load_data
    run_django
    ;;
  env)
    setup_env
    ;;
  data)
    load_data
    ;;
  django)
    run_django
    ;;
  docker)
    run_docker
    ;;
  clean)
    cleanup
    ;;
  help)
    show_help
    ;;
  *)
    echo -e "${RED}Invalid option! Use 'help' for usage information.${RESET}"
    ;;
esac
