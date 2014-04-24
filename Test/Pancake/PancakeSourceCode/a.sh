#!bin/bash
clear
gcc $1 -std=c99 -Werror -lm -o ../$(basename $1 ".c")
../$(basename $1 ".c")
