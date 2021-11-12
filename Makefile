# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 20:39:45 by rfelipe-          #+#    #+#              #
#    Updated: 2021/11/12 19:36:08 by rfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang
FLAGS = -g -Wall -Wextra -Werror
SANITIZE = -fsanitize=address

LIBFT_DIR = ./libft
LIBFT = libft/libft.a

INCLUDE_DIR = ./includes
INCLUDE = $(INCLUDE_DIR)/push_swap.h

OBJ_DIR = ./objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_DIR = ./src
SRC = $(SRC_DIR)/actions.c \
		$(SRC_DIR)/checkers.c \
		$(SRC_DIR)/fake_actions.c \
		$(SRC_DIR)/find_services.c \
		$(SRC_DIR)/moves_services.c \
		$(SRC_DIR)/normalize.c \
		$(SRC_DIR)/other_services.c \
		$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/quick_sort.c \
		$(SRC_DIR)/sorter.c \
		$(SRC_DIR)/stack_services.c \
		$(SRC_DIR)/throw_error.c

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) -lm $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32mPush swap compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(FLAGS) -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	@echo "\033[33mCompiling project...\n"
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[31mDeleting EVERYTHING...\n"
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)
	@echo "\033[31mProject cleaned up!"

re: fclean all
