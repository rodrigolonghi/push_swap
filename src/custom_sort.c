/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:25:34 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/25 20:21:59 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
