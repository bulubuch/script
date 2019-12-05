# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/10 23:31:33 by mbuch             #+#    #+#              #
#    Updated: 2019/12/04 08:33:53 by mbuch            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# SOURCES       															   #
################################################################################

SRCS		= script.c

################################################################################
# BASIC VARIABLES															   #
################################################################################

PATH_OBJ	= obj
PATH_SRC	= src
PATH_INC	= includes

NAME		= ft_script
CFLAGS		= -Wall -Wextra -Werror
OBJECTS		= $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))
DEBUG		= -g -O0

################################################################################
# RULES																		   #
################################################################################

.PHONY: all

all: $(NAME)

$(NAME): $(OBJECTS)
	@gcc -o $@ $(OBJECTS)

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.c)
	@mkdir -p $(PATH_OBJ)
	$(CC) -c -o $@ $(CFLAGS) $^ -O0 -g  -I $(PATH_INC)/

clean:
	@rm -f $(OBJECTS)
	@echo Delete $(words $(OBJECTS)) object file

fclean: clean
	rm -f $(NAME)
	rm -f libft_malloc.so

re: fclean $(NAME)

