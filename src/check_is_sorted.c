/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:37:07 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/10 17:57:49 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_is_sorted(t_stacks *s)
{
	int	x;
	int	y;

	x = 0;
	while (x < s->size - 1 && s->stack_a[x] != NULL)
	{
		y = x + 1;
		while (y < s->size && s->stack_a[y] != NULL)
		{
			if (ft_atoi(s->stack_a[x]) > ft_atoi(s->stack_a[y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
