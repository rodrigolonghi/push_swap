# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 20:39:45 by rfelipe-          #+#    #+#              #
#    Updated: 2022/04/02 23:13:28 by rfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

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
		$(SRC_DIR)/args_services.c \
		$(SRC_DIR)/check_sorter.c \
		$(SRC_DIR)/checkers.c \
		$(SRC_DIR)/fake_actions.c \
		$(SRC_DIR)/find_services.c \
		$(SRC_DIR)/moves_services.c \
		$(SRC_DIR)/normalize.c \
		$(SRC_DIR)/other_services.c \
		$(SRC_DIR)/quick_sort.c \
		$(SRC_DIR)/sorter.c \
		$(SRC_DIR)/stack_services.c \
		$(SRC_DIR)/throw_error.c \
		$(SRC_DIR)/checker_services.c

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) ./src/push_swap/push_swap.c -lm $(OBJ) $(LIBFT) -o $(NAME)
	@echo "Push swap compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(FLAGS) -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	@echo "Compiling project...\n"
	@make -C $(LIBFT_DIR)

bonus: $(LIBFT) $(OBJ)
	@$(CC) ./src/checker/checker.c -lm $(OBJ) $(LIBFT) -o $(CHECKER)
	@echo "Push swap checker compiled!"

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Deleting EVERYTHING...\n"
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)
	@rm -rf $(CHECKER)
	@echo "Project cleaned up!"

re: fclean all
