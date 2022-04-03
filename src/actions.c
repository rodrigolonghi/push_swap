/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:19:15 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/04/03 00:13:42 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	action_pa(t_stacks *s)
{
	int	x;
	int	aux;

	if (get_relative_size(s->stack_b, s->size) > 0)
	{
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
		save_next_move(s, "pa");
	}
}

void	action_pb(t_stacks *s)
{
	int	x;
	int	aux;

	if (get_relative_size(s->stack_a, s->size) > 0)
	{
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
		save_next_move(s, "pb");
	}
}

void	action_rrx(int *stack, int *optional, t_stacks *s, char c)
{
	int	x;
	int	aux;

	if (get_relative_size(stack, s->size) > 1)
	{
		x = get_relative_size(stack, s->size) - 1;
		aux = stack[x];
		while (x > 0)
		{
			stack[x] = stack[x - 1];
			x--;
		}
		stack[x] = aux;
		if (optional != NULL)
			action_rx(optional, NULL, s, 'x');
		if (c == 'a')
			save_next_move(s, "rra");
		else if (c == 'b')
			save_next_move(s, "rrb");
		else if (c == 's')
			save_next_move(s, "rrr");
	}
}

void	action_rx(int *stack, int *optional, t_stacks *s, char c)
{
	int	x;
	int	aux;

	if (get_relative_size(stack, s->size) > 1)
	{
		x = 0;
		aux = stack[0];
		while (x < get_relative_size(stack, s->size) - 1)
		{
			stack[x] = stack[x + 1];
			x++;
		}
		stack[x] = aux;
		if (optional != NULL)
			action_rx(optional, NULL, s, 'x');
		if (c == 'a')
			save_next_move(s, "ra");
		else if (c == 'b')
			save_next_move(s, "rb");
		else if (c == 's')
			save_next_move(s, "rr");
	}
}

void	action_sx(int *stack, int *optional, t_stacks *s, char c)
{
	int	aux;

	if (get_relative_size(stack, s->size) > 1)
	{
		aux = stack[0];
		stack[0] = stack[1];
		stack[1] = aux;
		if (optional != NULL)
			action_sx(optional, NULL, s, 'x');
		if (c == 'a')
			save_next_move(s, "sa");
		else if (c == 'b')
			save_next_move(s, "sb");
		else if (c == 's')
			save_next_move(s, "ss");
	}
}
