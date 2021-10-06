/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:13:42 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/06 01:32:50 by rfelipe-         ###   ########.fr       */
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
	ft_putendl_fd("pb", 1);
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
	ft_putendl_fd("pa", 1);
}

void	action_rrx(char **stack, char **stackOptional, int size, char c)
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
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	action_rx(char **stack, char **stackOptional, int size, char c)
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
	ft_putchar_fd('r', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	action_sx(char **stack, char **stackOptional, char c)
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
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}
