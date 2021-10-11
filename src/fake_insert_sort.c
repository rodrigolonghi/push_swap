/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_insert_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:40:14 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/11 01:36:38 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fake_insert_sort(t_stacks *f, int *moves)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < f->size && check_is_sorted(f) == 0)
	{
		x = 1;
		y = 0;
		while (x < f->size - i)
		{
			if (compare(f->stack_a[y], f->stack_a[x]) == 1)
				y = x;
			x++;
		}
		moves[0] += fake_to_top(f->stack_a, f->size - i, y);
		moves[0] += fake_action_pb(f);
		i++;
	}
	i = 0;
	while (i < f->size && f->stack_b[0] != NULL)
	{
		moves[0] += fake_action_pa(f);
		i++;
	}
}
