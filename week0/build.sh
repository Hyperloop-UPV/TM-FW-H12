#!/bin/bash

gcc main.c -o program.obj \
  -Wall -Wextra -Wno-<disabled-warn> \
  -pedantic \
  -I inc_dir \
  -L library_dir \
  -l library \
  -ggdb \
  -O3 \
  -c

#clang
