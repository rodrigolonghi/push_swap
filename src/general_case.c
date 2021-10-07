/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 01:47:04 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/07 02:42:28 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	to_top(char **stack, int size, int pos)
{
	char	*nbr;

	nbr = stack[pos];
	if (pos > size / 2)
	{
		while (ft_strncmp(stack[0], nbr, ft_strlen(nbr)) != 0)
			action_rrx(stack, NULL, size, 'a');
	}
	else
	{
		while (ft_strncmp(stack[0], nbr, ft_strlen(nbr)) != 0)
			action_rx(stack, NULL, size, 'a');
	}
}

void	general_case(char **stack_a, char **stack_b, int size)
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
		to_top(stack_a, size - i, y);
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
