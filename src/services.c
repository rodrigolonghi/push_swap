/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   services.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 02:07:25 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/11 01:04:19 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fake_to_top(char **stack, int size, int pos)
{
	int		moves;
	char	*nbr;

	moves = 0;
	nbr = stack[pos];
	if (pos > size / 2)
	{
		while (ft_atoi(stack[0]) != ft_atoi(nbr))
			moves += fake_action_rrx(stack, NULL, size);
	}
	else
	{
		if (pos == 1)
			moves += fake_action_sx(stack, NULL);
		else
		{
			while (ft_atoi(stack[0]) != ft_atoi(nbr))
				moves += fake_action_rx(stack, NULL, size);
		}
	}
	return (moves);
}

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
		if (ft_strncmp(stack[x], "ok", ft_strlen(stack[x])) != 0
			&& ft_atoi(stack[x]) == nbr)
			return (x);
		x++;
	}
	return (-1);
}
