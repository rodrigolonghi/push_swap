/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_services.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:11:59 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/24 20:02:19 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fake_to_top(char **stack, int size, int pos)
{
	int		moves;
	char	*nbr;
	int		relative_size;

	relative_size = find_relative_size(stack, size);
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

	relative_size = find_relative_size(stack, size);
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

void	throw_error(t_stacks *s)
{
	ft_putendl_fd("Error", 2);
	free_stack(s);
	exit(1);
}

int	compare(char *a, char *b)
{
	if (ft_atoi(a) > ft_atoi(b))
		return (1);
	else if (ft_atoi(a) < ft_atoi(b))
		return (-1);
	return (0);
}
