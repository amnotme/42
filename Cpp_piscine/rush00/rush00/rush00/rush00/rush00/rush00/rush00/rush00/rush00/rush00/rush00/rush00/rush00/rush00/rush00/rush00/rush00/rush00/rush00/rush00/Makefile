#!/usr/bin/make -f

################################################################################
# SETTINGS                                                                     #
################################################################################

NAME = ft_retro
CC = clang++
CFLAGS += -Wall -Werror -Wextra -Wimplicit -std=c++98 -pedantic
CFLAGS += #-Ofast
CFLAGS += -g -fsanitize=address
INC = -I inc
SRC_DIR = src
OBJ_DIR = obj

SRC = \
	main\
	Game\
	Window\
	Enemy\
	Entity\
	Player\
	Projectile\
	Rock\


OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

################################################################################
# COLORS                                                                       #
################################################################################

COLSIZE = 50
NC = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m

################################################################################
# RULES                                                                        #
################################################################################

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(YELLOW)%-$(COLSIZE)s$(NC)" "Building $@... "
	@$(CC) $(CFLAGS) -lncurses $(OBJ) -o $@
	@echo "$(GREEN)DONE$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo " > Compiling $<..."
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files removed$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed$(NC)"

re: fclean all
