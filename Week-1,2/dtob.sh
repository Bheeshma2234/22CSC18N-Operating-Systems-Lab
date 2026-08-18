#!/bin/bash
echo -n "Enter decimal number:"
read num

binary=""

while [ $num -gt 0 ]
do
    rem=$((num % 2))
    binary="$rem$binary"
    num=$((num / 2))
done

echo "Equivalent Binary number: $binary"
