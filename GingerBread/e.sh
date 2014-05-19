#!bin/bash
clear
g++ $1 -o ./executable/$(basename $1 ".cpp")
./executable/$(basename $1 ".cpp")

