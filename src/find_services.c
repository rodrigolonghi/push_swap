/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_services.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:48:56 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/24 20:00:50 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_smaller_and_bigger(t_stacks *s, int *sb)
{
	int	x;

	sb[0] = 0;
	sb[1] = 0;
	x = 1;
	while (x < s->size && s->stack_b[x] != NULL)
	{
		if (compare(s->stack_b[x], s->stack_b[sb[0]]) == -1)
			sb[0] = x;
		if (compare(s->stack_b[x], s->stack_b[sb[1]]) == 1)
			sb[1] = x;
		x++;
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

void	find_top_and_bottom(int *tb, t_stacks *s, int start, int limit)
{
	int	x;

	x = 0;
	tb[0] = -1;
	tb[1] = -1;
	while (x < s->size && (tb[0] == -1 || tb[1] == -1))
	{
		if (s->stack_a[x] != NULL
			&& (ft_atoi(s->stack_a[x]) >= ft_to_binary(start)
				&& ft_atoi(s->stack_a[x]) < ft_to_binary(limit))
			&& tb[0] == -1)
			tb[0] = x;
		if (s->stack_a[s->size - 1 - x] != NULL
			&& (ft_atoi(s->stack_a[s->size - 1 - x]) >= ft_to_binary(start)
				&& ft_atoi(s->stack_a[s->size - 1 - x])
				< ft_to_binary(limit))
			&& tb[1] == -1)
			tb[1] = s->size - 1 - x;
		x++;
	}
}

int	find_relative_size(char **stack, int original_size)
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
