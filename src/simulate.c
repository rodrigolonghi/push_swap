/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:50:37 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/15 03:25:33 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	simulate(t_stacks *s)
{
	int			*insert_moves;
	int			*radix_moves;
	t_stacks	f;

	insert_moves = ft_calloc(1, sizeof(int));
	radix_moves = ft_calloc(1, sizeof(int));
	duplicate_stack(&f, s);
	fake_insert_sort(&f, insert_moves);
	ft_free(&f);
	duplicate_stack(&f, s);
	fake_radix_sort(&f, radix_moves);
	ft_free(&f);
	if (insert_moves < radix_moves)
		return (1);
	return (2);
}
