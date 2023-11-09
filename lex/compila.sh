#!/usr/bin/bash

lex -L commands.lex
cc -c -g lex.yy.c
cc -c -g code.c
cc -g  code.c lex.yy.o -o code -ll
