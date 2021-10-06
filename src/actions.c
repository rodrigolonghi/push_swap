/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:13:42 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/05 21:15:05 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	action_pb(char **stack_a, char **stack_b, int size)
{
	char	*aux;
	int		i;

	i = size - 1;
	aux = stack_a[0];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = aux;
	i = 0;
	while (i < size - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[size - 1] = NULL;
}

void	action_pa(char **stack_a, char **stack_b, int size)
{
	char	*aux;
	int		i;

	i = size - 1;
	aux = stack_b[0];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = aux;
	i = 0;
	while (i < size - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[size - 1] = NULL;
}

void	action_rrx(char **stack, char **stackOptional, int size)
{
	char	*aux;
	int		i;

	aux = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = aux;
	if (stackOptional != NULL)
	{
		aux = stackOptional[size - 1];
		i = size - 1;
		while (i > 0)
		{
			stackOptional[i] = stackOptional[i - 1];
			i--;
		}
		stackOptional[0] = aux;
	}
}

void	action_rx(char **stack, char **stackOptional, int size)
{
	char	*aux;
	int		i;

	aux = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = aux;
	if (stackOptional != NULL)
	{
		aux = stackOptional[0];
		i = 0;
		while (i < size - 1)
		{
			stackOptional[i] = stackOptional[i + 1];
			i++;
		}
		stackOptional[size - 1] = aux;
	}
}

void	action_sx(char **stack, char **stackOptional)
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
}
