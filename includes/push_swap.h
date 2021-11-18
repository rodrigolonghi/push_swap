/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:44:06 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/18 20:46:34 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

typedef struct s_stacks
{
	int	moves;
	int	*moves_list;
	int	size;
	int	*stack_a;
	int	*stack_b;
}	t_stacks;

void	action_sx(int *stack, int *optional, t_stacks *s, char c);
void	action_rx(int *stack, int *optional, t_stacks *s, char c);
void	action_rrx(int *stack, int *optional, t_stacks *s, char c);
void	action_pa(t_stacks *s);
void	action_pb(t_stacks *s);
int		check_args(int n_args, char **args, int argc);
int		check_is_sorted(t_stacks *s);
void	create_stack(int n_args, char **args, t_stacks *s, int argc);
void	free_stack(t_stacks *s);
int		get_relative_size(int *stack, int original_size);
void	save_next_move(t_stacks *s, char *move);
void	sorter(t_stacks *s);
void	throw_error(void);
void	put_moves(t_stacks *s);
void	verify_arg(char *arg);
int		find_bigger_index(int *stack, int size);
int		find_index(int *stack, int size, int value);
void	to_top(int *stack, t_stacks *s, int pos, char c);
int		find_smaller_index(int *stack, int size);
void	normalize(t_stacks *s);
void	free_args(int n_args, char **args, int argc);
void	duplicate_stack(t_stacks *f, t_stacks *s);
void	find_top_and_bottom(int *tb, t_stacks *s, int start, int limit);
int		fake_action_sx(int *stack, int *optional, t_stacks *s);
int		fake_action_rx(int *stack, int *optional, t_stacks *s);
int		fake_action_rrx(int *stack, int *optional, t_stacks *s);
int		fake_action_pb(t_stacks *s);
int		fake_action_pa(t_stacks *s);
int		fake_to_top(int *stack, t_stacks *s, int pos);
void	quick_sort(t_stacks *s, int pivot);
int		get_args_number(int argc, char **argv);
void	free_all(t_stacks *s, t_list *list);
void	check_instruction(char *line, t_list *i, t_stacks *s);
void	check_sorter(t_stacks *s, t_list *i);

#endif
