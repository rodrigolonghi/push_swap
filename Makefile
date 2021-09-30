# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 23:27:22 by rfelipe-          #+#    #+#              #
#    Updated: 2021/09/29 23:48:56 by rfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = libft/libft.a

SRC_DIR = src
SRC = $(SRC_DIR)/push_swap.c

INCLUDE_DIR = includes
INCLUDE = $(INCLUDE_DIR)/push_swap.h

OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) -lm $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32mPush swap compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(FLAGS) -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	@echo "\033[33mCompiling project...\n"
	@make bonus -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[31mDeleting EVERYTHING...\n"
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)
	@echo "\033[31mProject cleaned up!"

re: fclean all
