#!/bin/bash

for ((i=0; i<10000; i++))
do  
    input=""
    for ((case=0; case<$RANDOM % 100 + 1; case++))
    do
        array=()
        for ((cnt=0; cnt<3; cnt++))
        do
            int1=`expr $RANDOM % 20001 - 10000`
            if ((int1 != -10000)) || ((int1 != 10000))
            then
                dec1=`expr $RANDOM % 1000`
            else
                dec1=0
            fi
            int2=`expr $RANDOM % 20001 - 10000`
            if ((int2 != -10000)) || ((int2 != 10000))
            then
                dec2=`expr $RANDOM % 1000`
            else
                dec2=0
            fi
            array[cnt]="$int1.$dec1 $int2.$dec2"
        done

        insert=`expr $RANDOM % 4`
        duplicate=`expr $RANDOM % 2 - \( $insert / 2 - 1 \) \* 2`
        for ((idx=4; idx>$insert; idx--))
        do
            array[idx]=${array[((idx - 1))]}
        done
        array[insert]=${array[duplicate]}

        input="$input"$'\n'"${array[0]} ${array[1]} ${array[2]} ${array[3]}"
    done
    input=${input:1}

    result_a=`./Math/Geometry/BOJ-01894-4번째점.out <<< $input`
    result_b=`./Math/Geometry/BOJ-01894-test.out <<< $input`

    if [[ "$result_a" != "$result_b" ]]
    then
        echo ------------------------------
        echo -e "$input"
        echo ----------
        echo -e "$result_a"
        echo ----------
        echo -e "$result_b"
    fi
done
