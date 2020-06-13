#!/bin/bash

rm *.csv

echo "'prawdopodobienstwo','stopandwait','gobackn'" >> procent.csv
for i in $(seq 100 -1 10)
do
    output=$(./arq.out 1000 $i 30 5)
    echo "$i, $output" >> procent.csv
done

echo "'ping','stopandwait','gobackn'" >> ping.csv
for i in $(seq 30 1 200)
do
    output=$(./arq.out 1000 95 $i 5)
    echo "$i, $output" >> ping.csv 
done

echo "'wielkosc ramki','stopandwait','gobackn'" >> ramka.csv
for i in $(seq 1 1 30)
do
    output=$(./arq.out 1000 95 30 $i)
    echo "$i, $output" >> ramka.csv
done
