#!/bin/bash

echo "enter the A value"
read a 
echo "enter the B value"
read b

c=`expr $a + $b`

echo "sum: "$c

c=`expr $a - $b`

echo "sub: "$c

c=`expr $a \* $b`

echo "mul:"$c

c=`expr $a / $b`

echo "div:"$c

ls

mkdir file1
touch new.txt

ls

rm -rf file1
rm new.txt

ls