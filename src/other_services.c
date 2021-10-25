/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_services.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:11:59 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/25 01:05:23 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fake_to_bottom(char **stack, int size, int pos)
{
	int		moves;
	char	*nbr;
	int		relative_size;

	moves = 0;
	relative_size = find_relative_size(stack, size);
	nbr = stack[pos];
	if (pos > relative_size / 2)
		while (ft_atoi(stack[relative_size - 1]) != ft_atoi(nbr))
			moves += fake_action_rrx(stack, NULL, relative_size);
	else
		while (ft_atoi(stack[relative_size - 1]) != ft_atoi(nbr))
			moves += fake_action_rx(stack, NULL, relative_size);
	return (moves);
}

void	to_bottom(char **stack, t_stacks *s, int pos, char c)
{
	char	*nbr;
	int		relative_size;

	relative_size = find_relative_size(stack, s->size);
	nbr = stack[pos];
	if (pos > relative_size / 2)
		while (ft_atoi(stack[relative_size - 1]) != ft_atoi(nbr))
			action_rrx(stack, NULL, s, c);
	else
		while (ft_atoi(stack[relative_size - 1]) != ft_atoi(nbr))
			action_rx(stack, NULL, s, c);
}

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
		while (ft_atoi(stack[0]) != ft_atoi(nbr))
			moves += fake_action_rx(stack, NULL, relative_size);
	}
	return (moves);
}

void	to_top(char **stack, t_stacks *s, int pos, char c)
{
	char	*nbr;
	int		relative_size;

	relative_size = find_relative_size(stack, s->size);
	nbr = stack[pos];
	if (pos > relative_size / 2)
	{
		while (ft_atoi(stack[0]) != ft_atoi(nbr))
			action_rrx(stack, NULL, s, c);
	}
	else
	{
		while (ft_atoi(stack[0]) != ft_atoi(nbr))
			action_rx(stack, NULL, s, c);
	}
}

int	compare(char *a, char *b)
{
	if (ft_atoi(a) > ft_atoi(b))
		return (1);
	else if (ft_atoi(a) < ft_atoi(b))
		return (-1);
	return (0);
}
