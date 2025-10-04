#!/usr/bin/env bash

while true; do
  echo "Select a food item:"
  echo "1. Pizza"
  echo "2. Burger"
  echo "3. Salad"
  echo "4. Pasta"
  echo "5. Exit"

  # Prompt the user for input, -p this use case is to tell the user to give theinput
  read -p "Enter your choice [1-5]: " food
  case $food in
  1)
    echo "Pizza has 266 calories."
    ;;
  2)
    echo "Burger has 189 calories."
    ;;
  3)
    echo "Salad has 210 calories."
    ;;
  4)
    echo "Pasta has 175 calories."
    ;;
  5)
    echo "Exiting."
    exit 0
    ;;
  *)
    echo "Invalid option. Please enter a number between 1 and 5."
    ;;
  esac
  echo
done
