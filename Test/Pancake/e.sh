#!bin/bash
gcc $1 -std=c99 -Werror -o $(basename $1 ".c")
./$(basename $1 ".c")
