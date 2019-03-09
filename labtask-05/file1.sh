#!/bin/bash



for arg in "$@"
do
echo "$arg"
done

add()
{
	c= `expr $1 + $2`
	echo "addition=$c"
}

add "$@" "$@"
