/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_services.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:19:55 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/12 18:20:36 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	duplicate_stack(t_stacks *f, t_stacks *s)
{
	int	x;

	x = 0;
	f->size = s->size;
	f->stack_a = ft_calloc(s->size + 1, sizeof(char *));
	f->stack_b = ft_calloc(s->size + 1, sizeof(char *));
	f->moves = 0;
	f->moves_list = NULL;
	while (x < s->size)
	{
		if (s->stack_a[x] != 0)
			f->stack_a[x] = s->stack_a[x];
		if (s->stack_b[x] != 0)
			f->stack_b[x] = s->stack_b[x];
		x++;
	}
}

void	create_stack(int n_args, char **args, t_stacks *s, int argc)
{
	int	x;

	s->size = n_args;
	s->stack_a = ft_calloc(n_args + 1, sizeof(int));
	s->stack_b = ft_calloc(n_args + 1, sizeof(int));
	x = 0;
	while (x < n_args)
	{
		s->stack_a[x] = ft_atoi(args[x]);
		x++;
	}
	normalize(s);
	if (argc == 2)
		free_args(n_args, args, argc);
}

void	free_stack(t_stacks *s)
{
	if (s->moves_list != NULL)
		free(s->moves_list);
	if (s->stack_a != NULL)
		free(s->stack_a);
	if (s->stack_b != NULL)
		free(s->stack_b);
	if (s != NULL)
		free(s);
}
