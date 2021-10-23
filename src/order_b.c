/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:18:45 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/20 23:06:42 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	order_b(t_stacks *s, int time)
{
	int	size_b;
	int	quarter;

	size_b = get_relative_size(s->stack_b, s->size);
	if (time == 1)
		quarter = to_binary(s->size / 4);
	else
		quarter = to_binary(s->size * 3 / 4);
	if (size_b > 0)
	{
		if (ft_atoi(s->stack_a[0]) > quarter)
			action_pb(s);
		else
		{
			action_pb(s);
			action_rx(s->stack_b, NULL, s->size, 'b');
		}
	}
	else
		action_pb(s);
}
