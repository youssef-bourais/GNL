#!/bin/bash

read n

cc -Wall -Wextra -Werror -D BUFFER_SIZE=$n  -fsanitize=address get_next_line.c
./a.out
