#!bin/bash
clear
gcc $1 -std=c99 -Werror -o $(basename $1 ".c")
./$(basename $1 ".c")
rm ./$(basename $1 ".c")
