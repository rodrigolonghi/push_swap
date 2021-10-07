/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:50:01 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/07 03:11:50 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case_five(char **stack_a, char **stack_b, int size)
{
	if (check_is_sorted(stack_a, 5) == 0)
	{
		action_pb(stack_a, stack_b, size);
		action_pb(stack_a, stack_b, size);
		if (compare(stack_b[0], stack_b[1]) == 0)
			action_sx(stack_b, NULL, 'b');
		case_three(stack_a, 'a');
		action_pa(stack_a, stack_b, size);
		if (compare(stack_a[0], stack_a[1]) == 1)
			action_rx(stack_a, NULL, 5, 'a');
		action_pa(stack_a, stack_b, size);
	}
}

void	case_three(char **stack, char c)
{
	if (check_is_sorted(stack, 3) == 0)
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
}

void	case_two(char **stack, char c)
{
	if (check_is_sorted(stack, 2) == 0)
	{
		if (compare(stack[0], stack[1]) == 1)
			action_sx(stack, NULL, c);
	}
}

void	sorter(char **stack_a, char **stack_b, int size)
{
	if (size == 2)
		case_two(stack_a, 'a');
	else if (size == 3)
		case_three(stack_a, 'a');
	else if (size == 5)
		case_five(stack_a, stack_b, size);
	else
		general_case(stack_a, stack_b, size);
}
