/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_or_less2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:25:34 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/23 01:37:36 by rfelipe-         ###   ########.fr       */
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
		relative_size = get_relative_size(s->stack_a, s->size);
		index = find_index(s->stack_a, s->size,
				to_binary(s->size / x * chunk - 1));
		if (index < relative_size / 2)
		{
			while (ft_atoi(s->stack_a[relative_size - 1])
				!= to_binary(s->size / x * chunk - 1))
				action_rx(s->stack_a, NULL, s->size, 'a');
		}
		else
			while (ft_atoi(s->stack_a[relative_size - 1])
				!= to_binary(s->size / x * chunk - 1))
				action_rrx(s->stack_a, NULL, s->size, 'a');
	}
	back_to_a(s, &f);
}

static void	send_best_to_b(int *tb, t_stacks *s)
{
	t_stacks	f;

	duplicate_stack(&f, s);
	if (fake_to_top(f.stack_a, f.size, tb[0])
		< fake_to_top(f.stack_a, f.size, tb[1]))
		to_top(s->stack_a, s->size, tb[0], 'a');
	else
		to_top(s->stack_a, s->size, tb[1], 'a');
	action_pb(s);
	ft_free(&f);
}

static void	get_top_and_bottom(int *tb, t_stacks *s, int chunk, int qtd)
{
	int	x;

	x = 0;
	while (x < s->size && (tb[0] == -1 || tb[1] == -1))
	{
		if (s->stack_a[x] != NULL
			&& (ft_atoi(s->stack_a[x]) >= to_binary(chunk * qtd)
				&& ft_atoi(s->stack_a[x]) < to_binary(qtd * (chunk + 1)))
			&& tb[0] == -1)
			tb[0] = x;
		if (s->stack_a[s->size - 1 - x] != NULL
			&& (ft_atoi(s->stack_a[s->size - 1 - x]) >= to_binary(chunk * qtd)
				&& ft_atoi(s->stack_a[s->size - 1 - x])
				< to_binary(qtd * (chunk + 1)))
			&& tb[1] == -1)
			tb[1] = s->size - 1 - x;
		x++;
	}
}

static void	to_b(t_stacks *s, int chunk, int x)
{
	int	qtd;
	int	*tb;

	qtd = s->size / x;
	tb = malloc(2 * sizeof(int));
	while (qtd > 0)
	{
		tb[0] = -1;
		tb[1] = -1;
		get_top_and_bottom(tb, s, chunk, s->size / x);
		send_best_to_b(tb, s);
		qtd--;
	}
	free(tb);
}

void	hundred_or_less2(t_stacks *s)
{
	int	chunk;
	int	x;

	chunk = 0;
	x = 5;
	while (chunk < x)
	{
		to_b(s, chunk, x);
		to_a(s, chunk, x);
		chunk++;
	}
}
