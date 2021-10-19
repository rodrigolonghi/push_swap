/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:17:45 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/15 17:10:33 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fake_action_pb(t_stacks *s)
{
	char	*aux;
	int		i;

	i = get_relative_size(s->stack_b, s->size) - 1;
	aux = s->stack_a[0];
	while (i > 0)
	{
		s->stack_b[i] = s->stack_b[i - 1];
		i--;
	}
	s->stack_b[0] = aux;
	i = 0;
	while (i < get_relative_size(s->stack_a, s->size) - 1)
	{
		s->stack_a[i] = s->stack_a[i + 1];
		i++;
	}
	s->stack_a[get_relative_size(s->stack_a, s->size) - 1] = NULL;
	return (1);
}

int	fake_action_pa(t_stacks *s)
{
	char	*aux;
	int		i;

	i = get_relative_size(s->stack_a, s->size) - 1;
	aux = s->stack_b[0];
	while (i > 0)
	{
		s->stack_a[i] = s->stack_a[i - 1];
		i--;
	}
	s->stack_a[0] = aux;
	i = 0;
	while (i < get_relative_size(s->stack_b, s->size) - 1)
	{
		s->stack_b[i] = s->stack_b[i + 1];
		i++;
	}
	s->stack_b[get_relative_size(s->stack_b, s->size) - 1] = NULL;
	return (1);
}

int	fake_action_rrx(char **stack, char **stackOptional, int size)
{
	char	*aux;
	int		i;

	aux = stack[get_relative_size(stack, size) - 1];
	i = get_relative_size(stack, size) - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = aux;
	if (stackOptional != NULL)
	{
		aux = stackOptional[get_relative_size(stack, size) - 1];
		i = get_relative_size(stack, size) - 1;
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
	while (i < get_relative_size(stack, size) - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[get_relative_size(stack, size) - 1] = aux;
	if (stackOptional != NULL)
	{
		aux = stackOptional[0];
		i = 0;
		while (i < get_relative_size(stack, size) - 1)
		{
			stackOptional[i] = stackOptional[i + 1];
			i++;
		}
		stackOptional[get_relative_size(stack, size) - 1] = aux;
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
