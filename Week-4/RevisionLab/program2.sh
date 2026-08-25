#!/bin/bash
echo "Enter three numbers:"
read a b c

if [ $a -le $b ] && [ $a -le $c ]
then
    echo "Smallest = $a"
elif [ $b -le $a ] && [ $b -le $c ]
then
    echo "Smallest = $b"
else
    echo "Smallest = $c"
fi
