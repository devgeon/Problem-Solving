#!/bin/bash

for ((i=0; i<10000; i++));
do
    s_len=`expr $RANDOM % 49 + 1`
    t_len=`expr $RANDOM % \( 50 - $s_len \) + $s_len + 1`
    s=`cat /dev/urandom | tr -dc 'A-B' | fold -w $s_len | sed 1q`
    t=`cat /dev/urandom | tr -dc 'A-B' | fold -w $t_len | sed 1q`
    result_a=`./Brute-Force/BOJ-12919-A와B2.out <<SEP
$s
$t
SEP`
    result_b=`./Brute-Force/BOJ-12919-test.out <<SEP
$s
$t
SEP`

    if (( result_a != result_b ))
    then
        echo ----------
        echo $s
        echo $t
        echo $result_a
        echo $result_b
    fi
done
