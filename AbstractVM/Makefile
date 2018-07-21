# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/19 04:48:11 by lhernand          #+#    #+#              #
#    Updated: 2018/07/21 05:10:28 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= vm
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -pedantic
CXXFILES	= main
INCLUDES	= -I ./
PATH		= ./
SRCFOLDER	= srcs
SRCFOLDERP	= ./$(SRCFOLDER)/
CXXOFILES	:= $(addsuffix .o, $(CXXFILES))
CXXOFILES	:= $(addprefix $(SRCFOLDERP),$(CXXOFILES))

all : $(NAME)

$(NAME) : $(CXXOFILES)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(INCLUDES) $(CXXOFILES)

$(CXXOFILES) :$(SRCFOLDERP)%.o: $(PATH)%.cpp
	/bin/mkdir -p $(SRCFOLDERP)
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $< -o $@

clean:
	/bin/rm -f $(CXXOFILES)
	/usr/bin/find . -name "$(SRCFOLDER)" -maxdepth 1 -type d -empty -delete

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
