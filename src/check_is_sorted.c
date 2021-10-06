/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:37:07 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/05 23:10:02 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_is_sorted(char **stack, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size - 1)
	{
		y = x + 1;
		while (y < size)
		{
			if (ft_atoi(stack[x]) > ft_atoi(stack[y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
