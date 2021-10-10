/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:34:03 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/10 01:09:07 by rfelipe-         ###   ########.fr       */
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

void	to_binary(char **stack_a, char **stack_temp, int size)
{
	int		*temp;
	char	*aux;

	temp = ft_calloc(3, sizeof(int));
	while (temp[0] < size)
	{
		temp[1] = 0;
		temp[2] = 0;
		aux = stack_temp[temp[0]];
		while (ft_memcmp(aux, "0", ft_strlen(aux)))
		{
			if (temp[1] > 0)
				temp[2] += ft_atoi(aux) % 2 * temp[1];
			else
				temp[2] = ft_atoi(aux) % 2;
			aux = ft_itoa(ft_atoi(aux) / 2);
			if (temp[1] == 0)
				temp[1] = 10;
			else
				temp[1] *= 10;
		}
		stack_a[temp[0]] = ft_itoa(temp[2]);
		temp[0]++;
	}
	free(temp);
}

void	indexing(char **stack_a, int size)
{
	int		x;
	int		y;
	char	*aux;
	char	**stack_temp;

	y = 0;
	stack_temp = ft_calloc(size, sizeof(char *));
	while (y < size)
	{
		x = 0;
		aux = "2147483647";
		while (x < size)
		{
			if (compare(stack_a[x], aux) == 0
				&& ft_strncmp(stack_a[x], "ok", ft_strlen(stack_a[x])) != 0)
				aux = stack_a[x];
			x++;
		}
		stack_temp[find_index(stack_a, size, ft_atoi(aux))] = ft_itoa(y);
		stack_a[find_index(stack_a, size, ft_atoi(aux))] = "ok";
		y++;
	}
	to_binary(stack_a, stack_temp, size);
	add_zero(stack_a, size);
	free(stack_temp);
}
