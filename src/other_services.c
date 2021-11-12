/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_services.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:33:57 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/12 17:53:46 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	fake_to_top(int *stack, t_stacks *s, int pos)
{
	int	moves;
	int	nbr;
	int	relative_size;

	relative_size = get_relative_size(stack, s->size);
	nbr = stack[pos];
	moves = 0;
	if (pos > relative_size / 2)
		while (stack[0] != nbr)
			moves += fake_action_rrx(stack, NULL, s);
	else
		while (stack[0] != nbr)
			moves += fake_action_rx(stack, NULL, s);
	return (moves);
}

void	to_top(int *stack, t_stacks *s, int pos, char c)
{
	int	nbr;
	int	relative_size;

	relative_size = get_relative_size(stack, s->size);
	nbr = stack[pos];
	if (pos > relative_size / 2)
		while (stack[0] != nbr)
			action_rrx(stack, NULL, s, c);
	else
		while (stack[0] != nbr)
			action_rx(stack, NULL, s, c);
}
