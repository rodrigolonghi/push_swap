/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:34:03 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/31 19:07:47 by rfelipe-         ###   ########.fr       */
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
	int		y;
	char	*aux;
	char	**stack_temp;

	y = 0;
	stack_temp = ft_calloc(s->size, sizeof(char *));
	while (y < s->size)
	{
		x = 0;
		aux = "2147483647";
		while (x < s->size)
		{
			if (compare(s->stack_a[x], aux) == -1 && ft_strncmp(s->stack_a[x],
					"ok", ft_strlen(s->stack_a[x])) != 0)
				aux = s->stack_a[x];
			x++;
		}
		stack_temp[find_index(s->stack_a, s->size, ft_atoi(aux))] = ft_itoa(y);
		s->stack_a[find_index(s->stack_a, s->size, ft_atoi(aux))] = "ok";
		y++;
	}
	arrange_stack(s->stack_a, stack_temp, s->size);
	free(stack_temp);
}
