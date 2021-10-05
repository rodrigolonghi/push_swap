/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:22:37 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/04 23:17:30 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_stacks(int *stackA, int size, char *args[])
{
	int	p;

	p = 0;
	while (p < size)
	{
		stackA[p] = ft_atoi(args[p + 1]);
		p++;
	}
}
