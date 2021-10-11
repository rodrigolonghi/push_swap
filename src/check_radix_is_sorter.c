/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_radix_is_sorter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 01:59:46 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/11 02:06:24 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_reverse_sorter(t_stacks *s)
{
	int	x;
	int	y;

	x = 0;
	while (x < s->size - 1 && s->stack_a[x] != NULL)
	{
		y = x + 1;
		while (y < s->size && s->stack_a[y] != NULL)
		{
			if (ft_atoi(s->stack_a[x]) < ft_atoi(s->stack_a[y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	check_radix_is_sorter(t_stacks *s)
{
	if (check_is_sorted(s) == 1)
		return (check_reverse_sorter(s));
	return (0);
}
