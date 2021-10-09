/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:33:29 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/09 03:06:30 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>

int		check_is_sorted(char **stack, int size);
int		compare(char *a, char *b);
int		find_index(char **stack, int size, int nbr);
int		get_args(char **argv, int argc);
void	action_pa(char **stack_a, char **stack_b, int size);
void	action_pb(char **stack_a, char **stack_b, int size);
void	action_rrx(char **stack, char **stackOptional, int size, char c);
void	action_rx(char **stack, char **stackOptional, int size, char c);
void	action_sx(char **stack, char **stackOptional, char c);
void	case_four(char **stack_a, char **stack_b);
void	case_three(char **stack, char c);
void	case_two(char **stack, char c);
void	check_args(char **args, int size);
void	create_stacks(char **stack, int size, char **args);
void	ft_print_stack(char **stack_a, char **stack_b, int size);
void	insert_sort(char **stack_a, char **stack_b, int size);
void	radix_sort(char **stack_a, char **stack_b, int size);
void	set_args(char **args, char **argv, int argc, int size);
void	sorter(char **stack_a, char **stack_b, int size);
void	throw_error(char *msg);
void	to_top(char **stack, int size, int pos, char c);

#endif
