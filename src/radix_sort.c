/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:54:36 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/11 03:02:56 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_stacks *s)
{
	int	x;
	int	len;
	int	moved;

	len = ft_strlen(s->stack_a[0]) - 1;
	while (len >= 0 && check_is_sorted(s) == 0)
	{
		x = 0;
		moved = 0;
		while (x < s->size && check_radix_is_sorter(s) == 0)
		{
			if (s->stack_a[0][len] == '0')
			{
				action_pb(s);
				moved++;
			}
			else
				action_rx(s->stack_a, NULL, s->size - moved, 'a');
			x++;
		}
		while (moved-- > 0)
			action_pa(s);
		len--;
	}
}
