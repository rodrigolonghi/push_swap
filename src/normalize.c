/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:34:03 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/12 18:13:09 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	normalize(t_stacks *s)
{
	int	x;
	int	aux;

	aux = find_bigger_index(s->stack_a, s->size);
	s->stack_b[aux] = s->size;
	x = 1;
	while (x < s->size)
	{
		aux = find_smaller_index(s->stack_a, s->size);
		s->stack_b[aux] = x;
		s->stack_a[aux] = 2147483647;
		x++;
	}
	x = 0;
	while (x < s->size)
	{
		s->stack_a[x] = s->stack_b[x];
		s->stack_b[x] = 0;
		x++;
	}
}
