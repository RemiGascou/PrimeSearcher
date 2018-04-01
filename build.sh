#!/bin/bash
gcc -Wall src/main.c src/lib/*.c -lm -o build/prime_searcher.out

read -n1 -p "Launch executable ? [y,n]" launch 
case $launch in  
  y|Y) clear; ./build/prime_searcher.out;;  
esac
echo ''
read -p "Execution ended."
