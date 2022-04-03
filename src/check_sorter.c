/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:57:37 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/04/02 22:18:21 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_action(t_stacks *s, int inst)
{
	if (inst == 0)
		fake_action_sx(s->stack_a, NULL, s);
	else if (inst == 1)
		fake_action_sx(s->stack_b, NULL, s);
	else if (inst == 2)
		fake_action_sx(s->stack_a, s->stack_b, s);
	else if (inst == 3)
		fake_action_rx(s->stack_a, NULL, s);
	else if (inst == 4)
		fake_action_rx(s->stack_b, NULL, s);
	else if (inst == 5)
		fake_action_rx(s->stack_a, s->stack_b, s);
	else if (inst == 6)
		fake_action_rrx(s->stack_a, NULL, s);
	else if (inst == 7)
		fake_action_rrx(s->stack_b, NULL, s);
	else if (inst == 8)
		fake_action_rrx(s->stack_a, s->stack_b, s);
	else if (inst == 9)
		fake_action_pa(s);
	else if (inst == 10)
		fake_action_pb(s);
}

void	check_sorter(t_stacks *s, int *inst, int size)
{
	int	x;

	x = 0;
	while (x < size)
	{
		do_action(s, inst[x]);
		x++;
	}
	if (check_is_sorted(s))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
