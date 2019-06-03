#!/bin/bash
touch timesteps.txt
touch pi.txt
touch steps.txt
touch absolutesteps.txt
touch relativesteps.txt
touch absolute.txt
touch relative.txt

gcc file.c -o file.out
acos=3.14159265
a=1000
while [ $a -lt 10000000 ]
do
./file.out $a
a=`expr $a \* 10`
done

while read line
do
	b=$line
	var=`echo "$b + 0" | bc`
	var2=`echo "$var - $acos" | bc`
	echo $var2 >> absolute.txt
	var3=`echo "$var2 / $acos" | bc`
	echo $var3 >> relative.txt
	var2=`echo "$var2" | awk ' { if($1>=0) { print $1} else {print $1*-1 }}'`
	var3=`echo "$var3" | awk ' { if($1>=0) { print $1} else {print $1*-1 }}'`
	echo $var3
	echo $var2
done < pi.txt

paste -d ' ' steps.txt absolute.txt >> absolutesteps.txt
paste -d ' ' steps.txt relative.txt >> relativesteps.txt
gnuplot -e 'set terminal png; plot "timesteps.txt" with lines' > graph1.png
gnuplot -e 'set terminal png; plot "absolutesteps.txt" with lines' > graph2.png
gnuplot -e 'set terminal png; plot "relativesteps.txt" with lines' > graph3.png


rm timesteps.txt
rm pi.txt
rm steps.txt
rm absolutesteps.txt
rm relativesteps.txt
rm absolute.txt
rm relative.txt
