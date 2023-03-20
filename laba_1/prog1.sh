#!/bin/bash

FILE="*.dat"
if [ "$1" ]
then
    if [ $(find . -maxdepth 1 -name "$1" | wc -l) -eq 1 ]
    then
        FILE="$1"
        cat -- "${FILE}"
        exit 1
    else
        echo "File not exists" >&2
        exit 1
    fi
fi

COUNTER=$(find . -maxdepth 1 -name "*.dat" | wc -l)

if [ $COUNTER -gt 1 ]
then
    echo "Error: more than 1 file with .dat exists" >&2
    exit 1
elif [ $COUNTER -eq 1 ]
then 
   cat *.dat
else
    echo "Error: less than 1 file with .dat exists" >&2
fi


