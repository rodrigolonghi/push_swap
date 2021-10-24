/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:33:29 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/24 20:02:19 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stacks
{
	int		size;
	char	**args;
	char	**stack_a;
	char	**stack_b;
}				t_stacks;

int		check_args(t_stacks *s);
int		check_duplicates(t_stacks *s);
int		check_is_sorted(t_stacks *s);
int		check_nbr_limit(t_stacks *s);
int		compare(char *a, char *b);
int		find_index(char **stack, int size, int nbr);
int		get_args_number(char **argv, int argc);
void	action_pa(t_stacks *s);
void	action_pb(t_stacks *s);
void	action_rx(char **stack, char **stackOptional, int size, char c);
void	action_rrx(char **stack, char **stackOptional, int size, char c);
void	action_sx(char **stack, char **stackOptional, char c);
void	add_zero(char **stack_a, int size);
void	case_five(t_stacks *s);
void	case_four(t_stacks *s);
void	case_three(char **stack, char c);
void	case_two(char **stack, char c);
void	create_args(int argc, char **argv, t_stacks *s);
void	create_stacks(t_stacks *s);
void	free_stack(t_stacks *s);
void	indexing(t_stacks *s);
void	insert_sort(t_stacks *s);
void	radix_sort(t_stacks *s);
void	sorter(t_stacks *s);
void	stack_to_binary(char **stack_a, char **stack_temp, int size);
void	to_top(char **stack, int size, int pos, char c);
void	throw_error(t_stacks *s);
int		fake_action_sx(char **stack, char **stackOptional);
int		fake_action_rx(char **stack, char **stackOptional, int size);
int		fake_action_rrx(char **stack, char **stackOptional, int size);
int		fake_action_pa(t_stacks *s);
int		fake_action_pb(t_stacks *s);
void	duplicate_stack(t_stacks *f, t_stacks *s);
int		simulate(t_stacks *s);
void	fake_insert_sort(t_stacks *f, int *moves);
void	fake_radix_sort(t_stacks *f, int *moves);
int		fake_to_top(char **stack, int size, int pos);
void	back_to_a(t_stacks *s, t_stacks *f);
int		find_relative_size(char **stack, int original_size);
void	find_smaller_and_bigger(t_stacks *s, int *sb);
void	custom_sort(t_stacks *s);
void	fake_custom_sorter(t_stacks *s, int *moves);
void	find_top_and_bottom(int *tb, t_stacks *s, int start, int limit);

#endif
