#!/bin/bash

echo -n "Enter a number: "
read n

t=$n
sum=0

while [ $n -gt 0 ]
do
    rem=$((n % 10))
    cube=$((rem * rem * rem))
    sum=$((sum + cube))
    n=$((n / 10))
done

if [ $sum -eq $t ]
then
    echo "$t is an Armstrong Number"
else
    echo "$t is not an Armstrong Number"
fi
