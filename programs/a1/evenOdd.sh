#!/bin/bash

# This program checks whether a number is even or odd

echo "Enter a number:"
read num
if [ $((num%2)) -eq 0 ]
then
echo "$num is even"
else
echo "$num is odd"
fi

# -eq is the operator to check whether the output is equal to 0 for maths
# == is the operator to check whether the output is equal to 1 mostly for strings
# fi is the end of the if statement