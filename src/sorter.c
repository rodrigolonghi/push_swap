/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:50:01 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/23 01:37:54 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case_five(t_stacks *s)
{
	int		x;
	int		y;
	char	*temp;

	y = 0;
	while (y < 2)
	{
		x = 0;
		temp = s->stack_a[0];
		while (x < 5 - y)
		{
			if (compare(temp, s->stack_a[x]) == 1)
				temp = s->stack_a[x];
			x++;
		}
		to_top(s->stack_a, 5 - y,
			find_index(s->stack_a, 5 - y, ft_atoi(temp)), 'a');
		action_pb(s);
		y++;
	}
	if (check_is_sorted(s) == 0)
		case_three(s->stack_a, 'a');
	action_pa(s);
	action_pa(s);
}

void	case_four(t_stacks *s)
{
	int		x;
	int		y;
	char	*temp;

	y = 0;
	while (y < 2)
	{
		x = 0;
		temp = s->stack_a[0];
		while (x < 4 - y)
		{
			if (compare(temp, s->stack_a[x]) == 1)
				temp = s->stack_a[x];
			x++;
		}
		to_top(s->stack_a, 4 - y,
			find_index(s->stack_a, 4 - y, ft_atoi(temp)), 'a');
		action_pb(s);
		y++;
	}
	case_two(s->stack_a, 'a');
	if (compare(s->stack_b[0], s->stack_b[1]) == -1)
		action_sx(s->stack_b, NULL, 'b');
	action_pa(s);
	action_pa(s);
}

void	case_three(char **stack, char c)
{
	if (compare(stack[2], stack[1]) == 1
		&& compare(stack[2], stack[0]) == 1)
		action_sx(stack, NULL, c);
	else if (compare(stack[2], stack[1]) == -1
		&& compare(stack[2], stack[0]) == -1)
	{
		if (compare(stack[1], stack[0]) == -1)
			action_sx(stack, NULL, c);
		action_rrx(stack, NULL, 3, c);
	}
	else
	{
		if (compare(stack[1], stack[0]) == 1)
			action_sx(stack, NULL, c);
		action_rx(stack, NULL, 3, c);
	}
}

void	case_two(char **stack, char c)
{
	if (compare(stack[0], stack[1]) == 1)
		action_sx(stack, NULL, c);
}

void	sorter(t_stacks *s)
{
	indexing(s);
	if (s->size == 2)
		case_two(s->stack_a, 'a');
	else if (s->size == 3)
		case_three(s->stack_a, 'a');
	else if (s->size == 4)
		case_four(s);
	else if (s->size == 5)
		case_five(s);
	else
		hundred_or_less(s);
	// else if (simulate(s) == 2)
	// 	insert_sort(s);
	// else
	// 	radix_sort(s);
}
