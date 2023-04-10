#!/bin/bash
/* This code helps compile the file */
gcc -Wall -Wextra -Werror -pedantic -c *.c
ar rc liball.a *.o
ranlib liball.a

