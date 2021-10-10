/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:22:37 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/10 05:04:55 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_stacks(t_stacks *s)
{
	int	p;

	p = 0;
	while (p < s->size)
	{
		s->stack_a[p] = s->args[p];
		p++;
	}
}
