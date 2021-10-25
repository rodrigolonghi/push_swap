/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:13:42 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/25 01:45:06 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	action_pb(t_stacks *s)
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
	write_next_move(s, "pb");
}

void	action_pa(t_stacks *s)
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
	write_next_move(s, "pa");
}

void	action_rrx(char **stack, char **stackOptional, t_stacks *s, char c)
{
	char	*aux;
	int		i;

	aux = stack[find_relative_size(stack, s->size) - 1];
	i = find_relative_size(stack, s->size) - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = aux;
	if (stackOptional != NULL)
		action_rrx(stackOptional, NULL, s, c);
	if (c == 'a')
		write_next_move(s, "rra");
	else if (c == 'b')
		write_next_move(s, "rrb");
	else
		write_next_move(s, "rrr");
}

void	action_rx(char **stack, char **stackOptional, t_stacks *s, char c)
{
	char	*aux;
	int		i;

	aux = stack[0];
	i = 0;
	while (i < find_relative_size(stack, s->size) - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[find_relative_size(stack, s->size) - 1] = aux;
	if (stackOptional != NULL)
		action_rx(stackOptional, NULL, s, c);
	if (c == 'a')
		write_next_move(s, "ra");
	else if (c == 'b')
		write_next_move(s, "rb");
	else
		write_next_move(s, "rr");
}

void	action_sx(char **stack, char **stackOptional, char c, t_stacks *s)
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
	if (c == 'a')
		write_next_move(s, "sa");
	else if (c == 'b')
		write_next_move(s, "sb");
	else
		write_next_move(s, "ss");
}
