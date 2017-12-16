clang -Wall -Wextra -Werror  -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror  -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o
