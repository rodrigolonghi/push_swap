/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:54:36 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/10 01:45:52 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(char **stack_a, char **stack_b, int size)
{
	int	x;
	int	len;
	int	moved;

	len = ft_strlen(stack_a[0]) - 1;
	while (len >= 0)
	{
		x = 0;
		moved = 0;
		while (x < size)
		{
			if (stack_a[0][len] == '0')
			{
				action_pb(stack_a, stack_b, size);
				moved++;
			}
			else
				action_rx(stack_a, NULL, size - moved, 'a');
			x++;
		}
		while (moved-- > 0)
			action_pa(stack_a, stack_b, size);
		len--;
	}
}
