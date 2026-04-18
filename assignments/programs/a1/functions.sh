#!/bin/bash

add() {
  echo $(($1 + $2))
}

sub() {
  echo $(($1-$2))
}

mul(){
  echo "$(($1*$2))"
}

div(){
  if(($2==0))
  then
    echo "Error: Division by zero"
  else
    echo $(($1/$2))
  fi
}

echo "Enter 1st number:"
read a
echo "Enter 2nd number:"
read b
c=$(add $a $b)
d=$(sub $a $b)
e=$(mul $a $b)
f=$(div $a $b)
echo "The sum is $c"
echo "The difference is $d"
echo "The product is $e"
echo "The division is $f"