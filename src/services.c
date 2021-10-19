/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   services.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 02:07:25 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/15 17:14:23 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_relative_size(char **stack, int original_size)
{
	int	x;

	x = 0;
	while (x < original_size)
	{
		if (stack[x] == NULL)
			break ;
		x++;
	}
	return (x);
}

int	fake_to_top(char **stack, int size, int pos)
{
	int		moves;
	char	*nbr;
	int		relative_size;

	relative_size = get_relative_size(stack, size);
	moves = 0;
	nbr = stack[pos];
	if (pos > relative_size / 2)
	{
		while (ft_atoi(stack[0]) != ft_atoi(nbr))
			moves += fake_action_rrx(stack, NULL, relative_size);
	}
	else
	{
		if (pos == 1)
			moves += fake_action_sx(stack, NULL);
		else
		{
			while (ft_atoi(stack[0]) != ft_atoi(nbr))
				moves += fake_action_rx(stack, NULL, relative_size);
		}
	}
	return (moves);
}

void	to_top(char **stack, int size, int pos, char c)
{
	char	*nbr;
	int		relative_size;

	relative_size = get_relative_size(stack, size);
	nbr = stack[pos];
	if (pos > relative_size / 2)
	{
		while (ft_atoi(stack[0]) != ft_atoi(nbr))
			action_rrx(stack, NULL, relative_size, c);
	}
	else
	{
		if (pos == 1)
			action_sx(stack, NULL, c);
		else
		{
			while (ft_atoi(stack[0]) != ft_atoi(nbr))
				action_rx(stack, NULL, relative_size, c);
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
