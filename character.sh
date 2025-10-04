#!/usr/bin/env bash

# Prompt the user to enter a filename
read -p "Enter the filename: " file

if [ ! -f "$file" ]; then
  echo "Error: File '$file' not found."
  exit 1
fi

echo No of vowels:$(grep -o -i [aeiou] "$file" | wc -l)
echo No of spaces:$(grep -o -i ' ' "$file" | wc -l)
echo No of characters:$(wc -m "$file")
echo No of Symbols:$(grep -o -i '[!@#%^]' "$file" | wc -l)
echo No of Lines:$(wc -l "$file")
