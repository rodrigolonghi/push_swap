/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_services.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:56:31 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/25 14:45:01 by rfelipe-         ###   ########.fr       */
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

void	duplicate_stack(t_stacks *f, t_stacks *s)
{
	int	x;

	x = 0;
	f->size = s->size;
	f->args = NULL;
	f->stack_a = ft_calloc(s->size + 1, sizeof(char *));
	f->stack_b = ft_calloc(s->size + 1, sizeof(char *));
	while (x < s->size)
	{
		if (s->stack_a[x] != NULL)
			f->stack_a[x] = s->stack_a[x];
		if (s->stack_b[x] != NULL)
			f->stack_b[x] = s->stack_b[x];
		x++;
	}
}

void	free_stack(t_stacks *s)
{
	if (s->stack_a != NULL)
		free(s->stack_a);
	if (s->stack_b != NULL)
		free(s->stack_b);
	if (s->args != NULL)
		free(s->args);
}
