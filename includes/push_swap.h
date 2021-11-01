/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:33:29 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/31 19:54:18 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stacks
{
	int		size;
	int		moves;
	char	**args;
	char	**stack_a;
	char	**stack_b;
	char	**moves_list;
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
void	action_rx(char **stack, char **stackOptional, t_stacks *s, char c);
void	action_rrx(char **stack, char **stackOptional, t_stacks *s, char c);
void	action_sx(char **stack, char **stackOptional, char c, t_stacks *s);
void	case_five(t_stacks *s);
void	case_four(t_stacks *s);
void	case_three(char **stack, char c, t_stacks *s);
void	case_two(char **stack, char c, t_stacks *s);
void	create_args(int argc, char **argv, t_stacks *s);
void	create_stacks(t_stacks *s);
void	free_stack(t_stacks *s);
void	indexing(t_stacks *s);
void	sorter(t_stacks *s);
void	to_top(char **stack, t_stacks *s, int pos, char c);
void	throw_error(t_stacks *s);
int		fake_action_sx(char **stack, char **stackOptional);
int		fake_action_rx(char **stack, char **stackOptional, int size);
int		fake_action_rrx(char **stack, char **stackOptional, int size);
int		fake_action_pa(t_stacks *s);
int		fake_action_pb(t_stacks *s);
void	duplicate_stack(t_stacks *f, t_stacks *s);
void	simulate(t_stacks *s, int aux);
int		fake_to_top(char **stack, int size, int pos);
int		find_relative_size(char **stack, int original_size);
void	find_smaller_and_bigger(t_stacks *s, int *sb);
void	find_top_and_bottom(int *tb, t_stacks *s, int start, int limit);
void	to_bottom(char **stack, t_stacks *s, int pos, char c);
int		fake_to_bottom(char **stack, int size, int pos);
int		find_smaller_index(char **stack, int size);
void	write_next_move(t_stacks *s, char *move);
void	put_moves(t_stacks *s);
void	clean_moves(t_stacks *s, char **action, int l);
void	quick_sort(t_stacks *s, int x);
void	fake_quick_sort(t_stacks *s, int x, int *moves);

#endif
