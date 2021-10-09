/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 02:07:25 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/09 02:50:15 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	to_top(char **stack, int size, int pos, char c)
{
	char	*nbr;

	nbr = stack[pos];
	if (pos > size / 2)
	{
		while (ft_atoi(stack[0]) != ft_atoi(nbr))
			action_rrx(stack, NULL, size, c);
	}
	else
	{
		if (pos == 1)
			action_sx(stack, NULL, c);
		else
		{
			while (ft_atoi(stack[0]) != ft_atoi(nbr))
				action_rx(stack, NULL, size, c);
		}
	}
}

int	find_index(char **stack, int size, int nbr)
{
	int	x;

	x = 0;
	while (x < size)
	{
		if (ft_atoi(stack[x]) == nbr)
			return (x);
		x++;
	}
	return (-1);
}
