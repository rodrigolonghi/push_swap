/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_services.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:18:33 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/12 19:21:53 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_top_and_bottom(int *tb, t_stacks *s, int start, int limit)
{
	int	x;

	x = 0;
	tb[0] = -1;
	tb[1] = -1;
	while (x < s->size && (tb[0] == -1 || tb[1] == -1))
	{
		if (s->stack_a[x] != 0 && s->stack_a[x] >= start
			&& s->stack_a[x] < limit && tb[0] == -1)
			tb[0] = x;
		if (s->stack_a[s->size - 1 - x] != 0
			&& s->stack_a[s->size - 1 - x] >= start
			&& s->stack_a[s->size - 1 - x] < limit && tb[1] == -1)
			tb[1] = s->size - 1 - x;
		x++;
	}
}

int	find_index(int *stack, int size, int value)
{
	int	x;

	x = 0;
	while (x < size)
	{
		if (stack[x] == value)
			return (x);
		x++;
	}
	return (-1);
}

int	find_smaller_index(int *stack, int size)
{
	int	x;
	int	aux;

	x = 0;
	aux = 0;
	while (x < size)
	{
		if (stack[x] < stack[aux])
			aux = x;
		x++;
	}
	return (aux);
}

int	find_bigger_index(int *stack, int size)
{
	int	x;
	int	aux;

	x = 0;
	aux = 0;
	while (x < size)
	{
		if (stack[x] > stack[aux])
			aux = x;
		x++;
	}
	return (aux);
}

int	get_relative_size(int *stack, int original_size)
{
	int	size;

	size = 0;
	while (size < original_size && stack[size] != 0)
		size++;
	return (size);
}
