/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:17:45 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/25 01:24:14 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fake_action_pb(t_stacks *s)
{
	char	*aux;
	int		i;
	int		size;

	i = find_relative_size(s->stack_b, s->size);
	aux = s->stack_a[0];
	while (i > 0)
	{
		s->stack_b[i] = s->stack_b[i - 1];
		i--;
	}
	s->stack_b[0] = aux;
	i = 0;
	size = find_relative_size(s->stack_a, s->size);
	while (i < size)
	{
		if (i + 1 < size)
			s->stack_a[i] = s->stack_a[i + 1];
		i++;
	}
	s->stack_a[find_relative_size(s->stack_a, s->size) - 1] = NULL;
	return (1);
}

int	fake_action_pa(t_stacks *s)
{
	char	*aux;
	int		i;
	int		size;

	i = find_relative_size(s->stack_a, s->size);
	aux = s->stack_b[0];
	while (i > 0)
	{
		s->stack_a[i] = s->stack_a[i - 1];
		i--;
	}
	s->stack_a[0] = aux;
	i = 0;
	size = find_relative_size(s->stack_b, s->size);
	while (i < size)
	{
		if (i + 1 < size)
			s->stack_b[i] = s->stack_b[i + 1];
		i++;
	}
	s->stack_b[find_relative_size(s->stack_b, s->size) - 1] = NULL;
	return (1);
}

int	fake_action_rrx(char **stack, char **stackOptional, int size)
{
	char	*aux;
	int		i;

	aux = stack[find_relative_size(stack, size) - 1];
	i = find_relative_size(stack, size) - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = aux;
	if (stackOptional != NULL)
	{
		aux = stackOptional[find_relative_size(stack, size) - 1];
		i = find_relative_size(stack, size) - 1;
		while (i > 0)
		{
			stackOptional[i] = stackOptional[i - 1];
			i--;
		}
		stackOptional[0] = aux;
	}
	return (1);
}

int	fake_action_rx(char **stack, char **stackOptional, int size)
{
	char	*aux;
	int		i;

	aux = stack[0];
	i = 0;
	while (i < find_relative_size(stack, size) - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[find_relative_size(stack, size) - 1] = aux;
	if (stackOptional != NULL)
	{
		aux = stackOptional[0];
		i = 0;
		while (i < find_relative_size(stack, size) - 1)
		{
			stackOptional[i] = stackOptional[i + 1];
			i++;
		}
		stackOptional[find_relative_size(stack, size) - 1] = aux;
	}
	return (1);
}

int	fake_action_sx(char **stack, char **stackOptional)
{
	char	*aux;

	aux = stack[0];
	stack[0] = stack[1];
	stack[1] = aux;
	if (stackOptional != NULL)
	{
		aux = stackOptional[0];
		stackOptional[0] = stackOptional[1];
		stackOptional[1] = aux;
	}
	return (1);
}
