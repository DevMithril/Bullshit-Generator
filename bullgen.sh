#!/bin/bash

if [ ! -f bullshit_generator ]
    then gcc -o bullshit_generator main.c -lm
fi

if (( $# == 1 ))
    then nb_sentence=$(($1))
else
    nb_sentence=$((1))
fi

while (( $nb_sentence > 0 ))
do
    ./bullshit_generator
    ((nb_sentence--))
    sleep 1
done

exit 0