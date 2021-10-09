/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 01:47:04 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/09 02:50:45 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_sort(char **stack_a, char **stack_b, int size)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < size)
	{
		x = 1;
		y = 0;
		while (x < size - i)
		{
			if (compare(stack_a[y], stack_a[x]) == 1)
				y = x;
			x++;
		}
		to_top(stack_a, size - i, y, 'a');
		action_pb(stack_a, stack_b, size);
		i++;
	}
	i = 0;
	while (i < size)
	{
		action_pa(stack_a, stack_b, size);
		i++;
	}
}
