#!/bin/bash

for ((i=0; i<10000; i++))
do
    n=`expr $RANDOM % 6 + 1`
    w=`expr $RANDOM % $n`
    t=`expr $RANDOM % 11 + 1`
    k=`expr $RANDOM % $n + 1`
    h=`expr $RANDOM % 51`
    heat="$h"
    for ((j=0; j<$n-1; j++))
    do
        h=`expr $RANDOM % 51`
        heat="$heat $h"
    done
    
    result_a=`python3 ./Brute-Force/BOJ-24884-장작넣기.py <<SEP
$n $w $t $k
$heat
SEP`
    result_b=`python3 ./Brute-Force/BOJ-24884-test.py <<SEP
$n $w $t $k
$heat
SEP`

    if (( result_a != result_b ))
    then
        echo ----------
        echo $n $w $t $k
        echo $heat
        echo $result_a
        echo $result_b
    fi
done
