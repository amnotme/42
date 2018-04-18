MAKE = make -C
LIB = src
NAME = ft_script
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = $(LIB)/libft.a \
		 ft_script.c

LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
		@$(LIBM)
		@$(CC) $(CFLAGS) -o $(NAME) -I $(CFILES)

clean:
		@$(LIBC)
		@$/bin/rm -f $(OBJECTS)

fclean:
		@$(LIBF)
		@$(/bin/rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
