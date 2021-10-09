/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:54:36 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/09 02:50:56 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	to_b(int *aux, char **stack_a, char **stack_b, int size)
{
	aux[0] = 0;
	while (aux[0] < 10)
	{
		aux[1] = 0;
		while (aux[1] < size && stack_a[aux[1]] != NULL)
		{
			if ((ft_atoi(stack_a[aux[1]]) / aux[3]) % 10 == aux[0]
				|| (ft_atoi(stack_a[aux[1]]) / aux[3]) % 10 == aux[0] * -1)
			{
				to_top(stack_a, size - aux[2], aux[1], 'a');
				action_pb(stack_a, stack_b, size);
				aux[2]++;
				aux[1] = -1;
			}
			aux[1]++;
		}
		aux[0]++;
	}
}

void	radix_sort(char **stack_a, char **stack_b, int size)
{
	int	*aux;

	aux = ft_calloc(4, sizeof(int));
	aux[3]++;
	while (check_is_sorted(stack_a, size) == 0)
	{
		to_b(aux, stack_a, stack_b, size);
		aux[0] = 0;
		while (aux[0] < size && stack_b[0] != NULL)
		{
			action_pa(stack_a, stack_b, size);
			aux[2]--;
			aux[0]++;
		}
		aux[3] *= 10;
	}
	free(aux);
}
