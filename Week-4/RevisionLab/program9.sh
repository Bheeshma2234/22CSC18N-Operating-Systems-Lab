#!/bin/bash
echo "Enter a string:"
read str
vowels=$(echo "$str" | grep -o "[AEIOUaeiou]" | wc -l)
consonants=$(echo "$str" | grep -o "[A-Za-z]" | grep -v "[AEIOUaeiou]" | wc -l)
digits=$(echo "$str" | grep -o "[0-9]" | wc -l)
echo "Vowels = $vowels"
echo "Consonants = $consonants"
echo "Digits = $digits"
