/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 02:50:05 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/12 19:24:20 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	case_two(t_stacks *s)
{
	if (s->stack_a[0] > s->stack_a[1])
	{
		if (s->moves == 0)
		{
			s->moves += 15;
			s->moves_list = ft_calloc(s->moves + 1, sizeof(int));
		}
		action_sx(s->stack_a, NULL, s, 'a');
	}
}

static void	case_three(t_stacks *s)
{
	if (s->moves == 0)
	{
		s->moves += 15;
		s->moves_list = ft_calloc(s->moves + 1, sizeof(int));
	}
	if (s->stack_a[2] > s->stack_a[1] && s->stack_a[2] > s->stack_a[0])
		action_sx(s->stack_a, NULL, s, 'a');
	else if (s->stack_a[2] < s->stack_a[1] && s->stack_a[2] < s->stack_a[0])
	{
		if (s->stack_a[1] < s->stack_a[0])
			action_sx(s->stack_a, NULL, s, 'a');
		action_rrx(s->stack_a, NULL, s, 'a');
	}
	else
	{
		if (s->stack_a[1] > s->stack_a[0])
			action_sx(s->stack_a, NULL, s, 'a');
		action_rx(s->stack_a, NULL, s, 'a');
	}
}

static void	case_four(t_stacks *s)
{
	int	x;

	if (s->moves == 0)
	{
		s->moves += 15;
		s->moves_list = ft_calloc(s->moves + 1, sizeof(int));
	}
	x = 0;
	while (x < 2)
	{
		to_top(s->stack_a, s, find_smaller_index(s->stack_a,
				get_relative_size(s->stack_a, s->size)), 'a');
		action_pb(s);
		x++;
	}
	case_two(s);
	action_pa(s);
	action_pa(s);
}

static void	case_five(t_stacks *s)
{
	int	x;

	if (s->moves == 0)
	{
		s->moves += 15;
		s->moves_list = ft_calloc(s->moves + 1, sizeof(int));
	}
	x = 0;
	while (x < 2)
	{
		to_top(s->stack_a, s, find_smaller_index(s->stack_a,
				get_relative_size(s->stack_a, s->size)), 'a');
		action_pb(s);
		x++;
	}
	if (check_is_sorted(s) == 0)
		case_three(s);
	action_pa(s);
	action_pa(s);
}

void	sorter(t_stacks *s)
{
	if (s->size == 2)
		case_two(s);
	else if (s->size == 3)
		case_three(s);
	else if (s->size == 4)
		case_four(s);
	else if (s->size == 5)
		case_five(s);
	else
	{
		s->moves = 15000;
		s->moves_list = ft_calloc(s->moves + 1, sizeof(int));
		if (s->size <= 100)
			quick_sort(s, 4);
		else
			quick_sort(s, 8);
	}
}
