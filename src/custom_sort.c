/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:25:34 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/25 02:01:13 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	organize_b(t_stacks *s)
// {
// 	int	pos;
// 	int	*diff;
// 	int	aux;

// 	pos = 0;
// 	diff = ft_calloc(2, sizeof(int));
// 	while (pos < find_relative_size(s->stack_b, s->size))
// 	{
// 		aux = ft_atoi(s->stack_b[pos]) - ft_atoi(s->stack_a[0]);
// 		if (aux < 0)
// 			aux *= -1;
// 		if (diff[0] == 0 || aux < diff[0])
// 		{
// 			diff[0] = aux;
// 			diff[1] = pos;
// 		}
// 		pos++;
// 	}
// 	if (ft_atoi(s->stack_b[diff[1]]) - ft_atoi(s->stack_a[0]) < 0)
// 		to_top(s->stack_b, s, diff[1], 'b');
// 	else
// 		to_bottom(s->stack_b, s, diff[1], 'b');
// 	action_pb(s);
// 	to_bottom(s->stack_b, s,
// 		find_smaller_index(s->stack_b, s->size), 'b');
// }

static void	to_a(t_stacks *s, int chunk, int x)
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
				action_rx(s->stack_a, NULL, s, 'a');
		}
		else
			while (ft_atoi(s->stack_a[relative_size - 1])
				!= ft_to_binary(s->size / x * chunk - 1))
				action_rrx(s->stack_a, NULL, s, 'a');
	}
	back_to_a(s, &f);
}

static void	send_best_to_b(int *tb, t_stacks *s, int chunk, int x)
{
	t_stacks	f;

	duplicate_stack(&f, s);
	if (fake_to_top(f.stack_a, f.size, tb[0])
		< fake_to_top(f.stack_a, f.size, tb[1]))
		to_top(s->stack_a, s, tb[0], 'a');
	else
		to_top(s->stack_a, s, tb[1], 'a');
	if (find_relative_size(s->stack_b, s->size) > 0)
	{
		if (ft_atoi(s->stack_a[0]) > ft_to_binary((s->size / x
					* (chunk + 1)) / 2))
			action_pb(s);
		else
		{
			action_pb(s);
			action_rx(s->stack_b, NULL, s, 'b');
		}
	}
	else
		action_pb(s);
	// if (find_relative_size(s->stack_b, s->size) > 1)
	// 	organize_b(s);
	// else
	// 	action_pb(s);
	// chunk += x;
	// chunk -= x;
	free_stack(&f);
}

static void	to_b(t_stacks *s, int chunk, int x)
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
		send_best_to_b(tb, s, chunk, x);
		qtd--;
	}
	if (chunk == x - 1 && s->size % x != 0)
	{
		qtd = (s->size / x) + (s->size % x);
		while (qtd > 0)
		{
			action_pb(s);
			qtd--;
		}
	}
	free(tb);
}

void	custom_sort(t_stacks *s)
{
	int	chunk;
	int	x;

	chunk = 0;
	x = 4;
	while (chunk < x)
	{
		to_b(s, chunk, x);
		to_a(s, chunk, x);
		chunk++;
	}
}
