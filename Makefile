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
SRC_NAME	=	main.c get_theinfo.c ft_bzero.c ft_error.c ft_memalloc.c\
				ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c\
				ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c\
				ft_strjoin.c ft_strlen.c ft_strncpy.c ft_strnew.c\
				get_next_line.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))
INCLUDES	=	-I $(INC_DIR)

all: $(NAME)

$(NAME): obj $(OBJ)
	@$(CC) $(FLAG) -o $(NAME) $(OBJ)
	@echo "\x1b[32mWhat_ismyIP :     -----Compilation completed-----\x1b[0m"

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAG) $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\x1b[34mLem-in :     -----Directory clean-----\x1b[0m"

fclean: clean
	@rm -rf $(NAME)

re: fclean all
