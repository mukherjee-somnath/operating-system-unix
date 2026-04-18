#!/bin/bash

# This program calculates the factorial of a number

echo "Enter a number:"
read num
factorial=1
for((i=1;i<=num;i++))
do
factorial=$((i*$factorial))
done
echo "The factorial of $num is $factorial"