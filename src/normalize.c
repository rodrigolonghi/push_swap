/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:34:03 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/24 20:00:50 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_zero(char **stack_a, int size)
{
	int		*aux;
	char	*temp;

	aux = ft_calloc(3, sizeof(int));
	while (aux[0] < size)
	{
		if (compare(stack_a[aux[0]], stack_a[aux[2]]) == 1)
			aux[2] = aux[0];
		aux[0]++;
	}
	aux[1] = ft_strlen(stack_a[aux[2]]);
	aux[0] = 0;
	while (aux[0] < size)
	{
		while (ft_strlen(stack_a[aux[0]]) < (size_t)aux[1])
		{
			temp = malloc(aux[1] * sizeof(char));
			temp = ft_strjoin("0", stack_a[aux[0]]);
			stack_a[aux[0]] = ft_strdup(temp);
			free(temp);
		}
		aux[0]++;
	}
	free(aux);
}

void	stack_to_binary(char **stack_a, char **stack_temp, int size)
{
	int		x;
	char	*aux;

	x = 0;
	while (x < size)
	{
		aux = stack_temp[x];
		stack_a[x] = ft_itoa(ft_to_binary(ft_atoi(aux)));
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
	stack_to_binary(s->stack_a, stack_temp, s->size);
	add_zero(s->stack_a, s->size);
	free(stack_temp);
}
