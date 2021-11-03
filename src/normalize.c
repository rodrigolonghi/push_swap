/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:34:03 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/02 21:29:15 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	arrange_stack(char **stack_a, char **stack_temp, int size)
{
	int	x;

	x = 0;
	while (x < size)
	{
		stack_a[x] = stack_temp[x];
		x++;
	}
}

void	indexing(t_stacks *s)
{
	int		x;
	int		aux;
	char	**stack_temp;

	x = 0;
	stack_temp = ft_calloc(s->size, sizeof(char *));
	while (x < s->size)
	{
		aux = find_smaller_index(s->stack_a, s->size);
		stack_temp[aux] = ft_itoa(x);
		s->stack_a[aux] = "ok";
		x++;
	}
	arrange_stack(s->stack_a, stack_temp, s->size);
	free(stack_temp);
}
