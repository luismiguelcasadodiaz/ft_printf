#!/bin/sh
# This tiny detail strips from the argument the file extension,  keeping in name only the file name.
# I reuse the filename to find the test files for each function i want to test the file name 
name=${1%.c}

norminette -R CheckForbiddenSourceHeader ../src/$1
cc -g -Wall -Wextra -Werror -c ../src/$1 ../src/ft_printf.h
cc -g -Wall -Wextra -Werror -c test_$name.c ../src/ft_printf.h
#LINUX cc -g -Wall -Wextra -Werror -o test_$name test_$name.o $name.o  -L../src -l:libftprintf.a
cc -g -Wall -Wextra -Werror  -o test_$name test_$name.o $name.o  -L../src -lftprintf
./test_$name
