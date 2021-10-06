/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:22:37 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/05 18:03:11 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_stacks(char **stack, int size, char *args[])
{
	int	p;

	p = 0;
	while (p < size)
	{
		stack[p] = args[p + 1];
		p++;
	}
}
