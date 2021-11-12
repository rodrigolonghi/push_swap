/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:43:29 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/12 17:53:05 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fake_action_pa(t_stacks *s)
{
	int	x;
	int	aux;

	x = 0;
	aux = s->stack_b[0];
	while (x < get_relative_size(s->stack_b, s->size) - 1)
	{
		s->stack_b[x] = s->stack_b[x + 1];
		x++;
	}
	s->stack_b[x] = 0;
	x = get_relative_size(s->stack_a, s->size);
	while (x > 0)
	{
		s->stack_a[x] = s->stack_a[x - 1];
		x--;
	}
	s->stack_a[0] = aux;
	return (1);
}

int	fake_action_pb(t_stacks *s)
{
	int	x;
	int	aux;

	x = 0;
	aux = s->stack_a[0];
	while (x < get_relative_size(s->stack_a, s->size) - 1)
	{
		s->stack_a[x] = s->stack_a[x + 1];
		x++;
	}
	s->stack_a[x] = 0;
	x = get_relative_size(s->stack_b, s->size);
	while (x > 0)
	{
		s->stack_b[x] = s->stack_b[x - 1];
		x--;
	}
	s->stack_b[0] = aux;
	return (1);
}

int	fake_action_rrx(int *stack, int *optional, t_stacks *s)
{
	int	x;
	int	aux;
	int	moves;

	x = get_relative_size(stack, s->size) - 1;
	aux = stack[x];
	moves = 0;
	while (x > 0)
	{
		stack[x] = stack[x - 1];
		x--;
	}
	stack[x] = aux;
	if (optional != NULL)
		moves += fake_action_rx(optional, NULL, s);
	moves++;
	return (moves);
}

int	fake_action_rx(int *stack, int *optional, t_stacks *s)
{
	int	x;
	int	aux;
	int	moves;

	x = 0;
	aux = stack[0];
	moves = 0;
	while (x < get_relative_size(stack, s->size) - 1)
	{
		stack[x] = stack[x + 1];
		x++;
	}
	stack[x] = aux;
	if (optional != NULL)
		moves += fake_action_rx(optional, NULL, s);
	moves++;
	return (moves);
}

int	fake_action_sx(int *stack, int *optional, t_stacks *s)
{
	int	aux;
	int	moves;

	moves = 0;
	aux = stack[0];
	stack[0] = stack[1];
	stack[1] = aux;
	if (optional != NULL)
		moves += fake_action_sx(optional, NULL, s);
	moves++;
	return (moves);
}
