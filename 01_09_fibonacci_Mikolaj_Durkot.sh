#!/bin/bash

if [ $# -ne 1 ] 
then
        exit
else
        a1=0;
        a2=1;
        temp=0;
        for ((i=0; i<$1; i++))
        do
                echo -n "$a1 "
                temp=$((a1 + a2));
                a1=$a2
                a2=$temp;
        done
        echo ""
fi
