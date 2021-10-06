# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 23:27:22 by rfelipe-          #+#    #+#              #
#    Updated: 2021/10/05 23:15:56 by rfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = libft/libft.a

SRC_DIR = ./src
SRC = $(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/throw_error.c \
		$(SRC_DIR)/create_stacks.c \
		$(SRC_DIR)/check_args.c \
		$(SRC_DIR)/actions.c \
		$(SRC_DIR)/check_is_sorted.c

INCLUDE_DIR = ./includes
INCLUDE = $(INCLUDE_DIR)/push_swap.h

OBJ_DIR = ./objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_DIR_BONUS = ./bonus/src
SRC_BONUS = $(SRC_DIR_BONUS)/checker.c

INCLUDE_DIR_BONUS = ./bonus/includes
INCLUDE_BONUS = $(INCLUDE_DIR_BONUS)/checker.h

OBJ_DIR_BONUS = ./bonus/objs
OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

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
	@rm -rf $(OBJ_DIR_BONUS)

fclean: clean
	@echo "\033[31mDeleting EVERYTHING...\n"
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@echo "\033[31mProject cleaned up!"

re: fclean all

bonus: $(LIBFT) $(OBJ_BONUS)
	@$(CC) -lm $(OBJ_BONUS) $(LIBFT) -o $(BONUS)
	@echo "\033[32mChecker compiled!"

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c $(INCLUDE_BONUS)
	@mkdir -p $(OBJ_DIR_BONUS)
	@$(CC) -c $(FLAGS) -I$(INCLUDE_DIR_BONUS) -o $@ $<