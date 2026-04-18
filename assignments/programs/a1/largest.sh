#!/bin/bash

# This program finds the largest number in a list of numbers

echo "Enter the numbers:"
read num1 num2 num3

if(($num1 > $num2))
then
max=$num1
else
max=$num2
fi

if(($num3 > $max))
then
max=$num3
fi

echo "The largest number is $max"