#!/bin/bash
gcc -Wall src/main.c src/lib/*.c -lm -o build/PrimeSearcher

read -n1 -p "Launch executable ? [y,n]" launch
case $launch in
  y|Y) clear; ./build/PrimeSearcher;;
esac
echo ''
read -p "Execution ended."
