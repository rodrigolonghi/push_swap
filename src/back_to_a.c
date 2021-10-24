/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:09:49 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/24 20:02:19 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	smart_back(t_stacks *s, t_stacks *f, int *sb)
{
	int	on_top;

	on_top = 0;
	find_smaller_and_bigger(s, sb);
	if (fake_to_top(f->stack_b, f->size, sb[0])
		< fake_to_top(f->stack_b, f->size, sb[1]))
	{
		to_top(s->stack_b, f->size, sb[0], 'b');
		action_pa(s);
		action_rx(s->stack_a, NULL, s->size, 'a');
	}
	else
	{
		to_top(s->stack_b, f->size, sb[1], 'b');
		action_pa(s);
		on_top++;
	}
	return (on_top);
}

void	back_to_a(t_stacks *s, t_stacks *f)
{
	int	*sb;
	int	size_b;
	int	x;
	int	on_top;

	x = 0;
	on_top = 0;
	size_b = find_relative_size(s->stack_b, s->size);
	sb = ft_calloc(2, sizeof(int));
	while (x < size_b)
	{
		duplicate_stack(f, s);
		if (size_b - x > 1)
			on_top += smart_back(s, f, sb);
		else
			action_pa(s);
		x++;
		free_stack(f);
	}
	while (on_top >= 0)
	{
		action_rx(s->stack_a, NULL, s->size, 'a');
		on_top--;
	}
}
