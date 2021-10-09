/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:50:01 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/09 03:01:10 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case_five(char **stack_a, char **stack_b)
{
	int		x;
	int		y;
	char	*temp;

	y = 0;
	while (y < 2)
	{
		x = 0;
		temp = stack_a[0];
		while (x < 5 - y)
		{
			if (compare(temp, stack_a[x]) == 1)
				temp = stack_a[x];
			x++;
		}
		to_top(stack_a, 5 - y, find_index(stack_a, 5 - y, ft_atoi(temp)), 'a');
		action_pb(stack_a, stack_b, 5);
		y++;
	}
	if (check_is_sorted(stack_a, 3) == 0)
		case_three(stack_a, 'a');
	action_pa(stack_a, stack_b, 5);
	action_pa(stack_a, stack_b, 5);
}

void	case_four(char **stack_a, char **stack_b)
{
	int		x;
	int		y;
	char	*temp;

	y = 0;
	while (y < 2)
	{
		x = 0;
		temp = stack_a[0];
		while (x < 4 - y)
		{
			if (compare(temp, stack_a[x]) == 1)
				temp = stack_a[x];
			x++;
		}
		to_top(stack_a, 4 - y, find_index(stack_a, 4 - y, ft_atoi(temp)), 'a');
		action_pb(stack_a, stack_b, 4);
		y++;
	}
	case_two(stack_a, 'a');
	if (compare(stack_b[0], stack_b[1]) == 0)
		action_sx(stack_b, NULL, 'b');
	action_pa(stack_a, stack_b, 4);
	action_pa(stack_a, stack_b, 4);
}

void	case_three(char **stack, char c)
{
	if (compare(stack[2], stack[1]) == 1
		&& compare(stack[2], stack[0]) == 1)
		action_sx(stack, NULL, c);
	else if (compare(stack[2], stack[1]) == 0
		&& compare(stack[2], stack[0]) == 0)
	{
		if (compare(stack[1], stack[0]) == 0)
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

void	sorter(char **stack_a, char **stack_b, int size)
{
	if (size == 2)
		case_two(stack_a, 'a');
	else if (size == 3)
		case_three(stack_a, 'a');
	else if (size == 4)
		case_four(stack_a, stack_b);
	else if (size == 5)
		case_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, size);
}
