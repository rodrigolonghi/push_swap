/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_or_less.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:00:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/23 01:39:14 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_top_and_bottom(int	*tb, t_stacks *s, int time)
{
	int	x;

	x = 0;
	while (x < s->size && tb[0] == -1)
	{
		if (time == 1 && s->stack_a[x] != NULL
			&& ft_atoi(s->stack_a[x]) < to_binary(s->size / 2))
			tb[0] = x;
		else if (time == 2 && s->stack_a[x] != NULL
			&& ft_atoi(s->stack_a[x]) >= to_binary(s->size / 2))
			tb[0] = x;
		x++;
	}
	x = s->size - 1;
	while (x >= 0 && tb[1] == -1)
	{
		if (time == 1 && s->stack_a[x] != NULL
			&& ft_atoi(s->stack_a[x]) < to_binary(s->size / 2))
			tb[1] = x;
		else if (time == 2 && s->stack_a[x] != NULL
			&& ft_atoi(s->stack_a[x]) >= to_binary(s->size / 2))
			tb[1] = x;
		x--;
	}
}

static void	second_half_to_b(t_stacks *s, t_stacks *f)
{
	int	x;
	int	middle;
	int	*tb;

	x = 0;
	if (s->size % 2 == 0)
		x++;
	middle = to_binary(s->size / 2);
	tb = malloc(2 * sizeof(int));
	while (x <= s->size / 2)
	{
		tb[0] = -1;
		tb[1] = -1;
		duplicate_stack(f, s);
		find_top_and_bottom(tb, s, 2);
		if (fake_to_top(f->stack_a, s->size, tb[0])
			< fake_to_top(f->stack_a, s->size, tb[1]))
			to_top(s->stack_a, s->size, tb[0], 'a');
		else
			to_top(s->stack_a, s->size, tb[1], 'a');
		ft_free(f);
		action_pb(s); //order_b(s, 1);
		x++;
	}
	free(tb);
}

static void	first_half_to_b(t_stacks *s, t_stacks *f)
{
	int	x;
	int	middle;
	int	*tb;

	x = 0;
	middle = to_binary(s->size / 2);
	tb = malloc(2 * sizeof(int));
	while (x < s->size / 2)
	{
		tb[0] = -1;
		tb[1] = -1;
		duplicate_stack(f, s);
		find_top_and_bottom(tb, s, 1);
		if (fake_to_top(f->stack_a, s->size, tb[0])
			< fake_to_top(f->stack_a, s->size, tb[1]))
			to_top(s->stack_a, s->size, tb[0], 'a');
		else
			to_top(s->stack_a, s->size, tb[1], 'a');
		action_pb(s); //order_b(s, 1);
		ft_free(f);
		x++;
	}
	free(tb);
}

void	hundred_or_less(t_stacks *s)
{
	t_stacks	f;

	first_half_to_b(s, &f);
	back_to_a(s, &f);
	if (check_is_sorted(s) == 0)
	{
		second_half_to_b(s, &f);
		back_to_a(s, &f);
	}
}
