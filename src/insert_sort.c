/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 01:47:04 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/10 18:07:22 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_sort(t_stacks *s)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < s->size)
	{
		x = 1;
		y = 0;
		while (x < s->size - i)
		{
			if (compare(s->stack_a[y], s->stack_a[x]) == 1)
				y = x;
			x++;
		}
		to_top(s->stack_a, s->size - i, y, 'a');
		action_pb(s);
		i++;
	}
	i = 0;
	while (i < s->size)
	{
		action_pa(s);
		i++;
	}
}
