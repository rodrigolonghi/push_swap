/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_radix_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:40:10 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/11 03:02:46 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fake_radix_sort(t_stacks *f, int *moves)
{
	int	x;
	int	len;
	int	moved;

	len = ft_strlen(f->stack_a[0]) - 1;
	while (len >= 0 && check_is_sorted(f) == 0)
	{
		x = 0;
		moved = 0;
		while (x < f->size && check_radix_is_sorter(f) == 0)
		{
			if (f->stack_a[0][len] == '0')
			{
				moves[0] += fake_action_pb(f);
				moved++;
			}
			else
				moves[0] += fake_action_rx(f->stack_a, NULL, f->size - moved);
			x++;
		}
		while (moved-- > 0)
			moves[0] += fake_action_pa(f);
		len--;
	}
}
