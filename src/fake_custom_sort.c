/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_custom_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:14:14 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/25 01:19:11 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	organize_b(t_stacks *s)
{
	int	*diff;
	int	*aux;

	aux = ft_calloc(3, sizeof(int));
	diff = ft_calloc(2, sizeof(int));
	while (aux[0] < find_relative_size(s->stack_b, s->size))
	{
		aux[1] = ft_atoi(s->stack_b[aux[0]]) - ft_atoi(s->stack_a[0]);
		if (aux[1] < 0)
			aux[1] *= -1;
		if (diff[0] == 0 || aux[1] < diff[0])
		{
			diff[0] = aux[1];
			diff[1] = aux[0];
		}
		aux[0]++;
	}
	if (ft_atoi(s->stack_b[diff[1]]) - ft_atoi(s->stack_a[0]) < 0)
		aux[2] += fake_to_top(s->stack_b, s->size, diff[1]);
	else
		aux[2] += fake_to_bottom(s->stack_b, s->size, diff[1]);
	aux[2] += fake_action_pb(s);
	aux[2] += fake_to_bottom(s->stack_b, s->size,
			find_smaller_index(s->stack_b, s->size));
	return (aux[2]);
}

static void	to_a(t_stacks *s, int chunk, int x, int *moves)
{
	t_stacks	f;
	int			index;
	int			relative_size;

	duplicate_stack(&f, s);
	if (chunk > 0)
	{
		relative_size = find_relative_size(s->stack_a, s->size);
		index = find_index(s->stack_a, s->size,
				ft_to_binary(s->size / x * chunk - 1));
		if (index < relative_size / 2)
		{
			while (ft_atoi(s->stack_a[relative_size - 1])
				!= ft_to_binary(s->size / x * chunk - 1))
				moves[0] += fake_action_rx(s->stack_a, NULL, s->size);
		}
		else
			while (ft_atoi(s->stack_a[relative_size - 1])
				!= ft_to_binary(s->size / x * chunk - 1))
				moves[0] += fake_action_rrx(s->stack_a, NULL, s->size);
	}
	fake_back_to_a(s, &f, moves);
}

static int	send_best_to_b(int *tb, t_stacks *s, int chunk, int x)
{
	int			moves;
	t_stacks	f;

	moves = 0;
	duplicate_stack(&f, s);
	if (fake_to_top(f.stack_a, f.size, tb[0])
		< fake_to_top(f.stack_a, f.size, tb[1]))
		moves += fake_to_top(s->stack_a, s->size, tb[0]);
	else
		moves += fake_to_top(s->stack_a, s->size, tb[1]);
	// if (find_relative_size(s->stack_b, s->size) > 0)
	// {
	// 	if (ft_atoi(s->stack_a[0]) > ft_to_binary((s->size / x
	// 				* (chunk + 1)) / 2))
	// 		moves += fake_action_pb(s);
	// 	else
	// 	{
	// 		moves += fake_action_pb(s);
	// 		moves += fake_action_rx(s->stack_b, NULL, s->size);
	// 	}
	// }
	// else
	// 	moves += fake_action_pb(s);
	if (find_relative_size(s->stack_b, s->size) > 1)
		moves += organize_b(s);
	else
		moves += fake_action_pb(s);
	chunk += x;
	chunk -= x;
	free_stack(&f);
	return (moves);
}

static void	to_b(t_stacks *s, int chunk, int x, int *moves)
{
	int	qtd;
	int	*tb;

	qtd = s->size / x;
	tb = malloc(2 * sizeof(int));
	while (qtd > 0)
	{
		if (chunk == x - 1 && s->size % x != 0)
			break ;
		find_top_and_bottom(tb, s, chunk * (s->size / x),
			(s->size / x) * (chunk + 1));
		moves[0] += send_best_to_b(tb, s, chunk, x);
		qtd--;
	}
	if (chunk == x - 1 && s->size % x != 0)
	{
		qtd = (s->size / x) + (s->size % x);
		while (qtd > 0)
		{
			moves[0] += fake_action_pb(s);
			qtd--;
		}
	}
	free(tb);
}

void	fake_custom_sort(t_stacks *s, int	*moves)
{
	int	chunk;
	int	x;

	chunk = 0;
	x = 4;
	while (chunk < x)
	{
		to_b(s, chunk, x, moves);
		to_a(s, chunk, x, moves);
		chunk++;
	}
}
