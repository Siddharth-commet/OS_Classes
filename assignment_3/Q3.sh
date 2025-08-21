#!/bin/bash
#Write a shell program to generate Fibonacci series.

echo "How many fibbonaci numbers: "
read i

fib=1
one=0
temp=0;

for (( it=1; it<=i; it++ ))
do 
    echo "$it: $fib"
    temp=$one
    one=$fib
    fib=$((temp+one))
    

done
