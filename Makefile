# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvelluet <bvelluet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/31 18:55:37 by bvelluet          #+#    #+#              #
#*   Updated: 2017/09/24 13:53:13 by bvelluet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #


.PHONY: all, $(NAME), obj, $(OBJ_DIR)%.o, $(LIBFT), clean, fclean, re

NAME		=	what_ismyIP
CC			=	gcc
FLAG		=	-Wall -Wextra -Werror
INC_DIR		=	./includes/
SRC_DIR		=	./srcs/
OBJ_DIR		=	./objs/
LIB_DIR		=	./libft/
SRC_NAME	=	main.c get_theinfo.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))
INCLUDES	=	-I $(LIB_DIR) -I $(INC_DIR)
LIB_LINK	=	-L $(LIB_DIR) -lft
LIBFT		=	$(addprefix $(LIB_DIR), libft.a)

all: $(NAME)

$(NAME): obj $(LIBFT) $(OBJ)
	@$(CC) $(FLAG) $(LIB_LINK) -o $(NAME) $(OBJ)
	@echo "\x1b[32mWhat_ismyIP :     -----Compilation completed-----\x1b[0m"

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAG) $(INCLUDES) -o $@ -c $<

$(LIBFT):
	@make -C $(LIB_DIR)

clean:
	@make clean -C $(LIB_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "\x1b[34mLem-in :     -----Directory clean-----\x1b[0m"

fclean: clean
	@rm -rf  $(LIBFT)
	@rm -rf $(NAME)

re: fclean all
