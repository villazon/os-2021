#!/bin/bash

END=100

for i in $(seq 1 $END);do
    echo $i
    ./client-rw $i &
done
