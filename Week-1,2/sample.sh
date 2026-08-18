#!/bin/bash
echo "Welcome to Shell Scripting"
echo "Linux Operating System"
name=Bheeshma
echo $name

echo -n "Enter Number : "
read n

if [ $n -le 1 ]
then
    echo "$n is not a prime number."
    exit 0
fi

for ((i=2; i<=n/2; i++))
do
    ans=$((n%i))

    if [ $ans -eq 0 ]
    then
        echo "$n is not a prime number."
        exit 0
    fi
done

echo "$n is a prime number."
