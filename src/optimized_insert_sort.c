/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_insert_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:00:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/15 03:32:36 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	find_smaller_and_bigger(t_stacks *s, int *s_n_b)
{
	int	x;

	s_n_b[0] = 0;
	s_n_b[1] = 0;
	x = 1;
	while (x < s->size && s->stack_b[x] != NULL)
	{
		if (compare(s->stack_b[x], s->stack_b[s_n_b[0]]) == -1)
			s_n_b[0] = x;
		if (compare(s->stack_b[x], s->stack_b[s_n_b[1]]) == 1)
			s_n_b[1] = x;
		x++;
	}
}

static void	back_to_a2(t_stacks *s, t_stacks *f, int *s_n_b, int *aux)
{
	find_smaller_and_bigger(s, s_n_b);
	if (fake_to_top(f->stack_b, aux[0] - aux[1], s_n_b[0])
		< fake_to_top(f->stack_b, aux[0] - aux[1], s_n_b[1]))
	{
		to_top(s->stack_b, aux[0] - aux[1], s_n_b[0], 'b');
		action_pa(s);
		action_rx(s->stack_a, NULL, aux[0] + aux[1] + 1, 'a');
	}
	else
	{
		to_top(s->stack_b, aux[0] - aux[1], s_n_b[1], 'b');
		action_pa(s);
		aux[2]++;
	}
}

static void	back_to_a(t_stacks *s, t_stacks *f)
{
	int			*s_n_b;
	int			*aux;

	aux = ft_calloc(3, sizeof(int));
	aux[0] = s->size / 2;
	s_n_b = ft_calloc(2, sizeof(int));
	while (aux[1] < aux[0])
	{
		duplicate_stack(f, s);
		if (aux[0] - aux[1] > 1)
			back_to_a2(s, f, s_n_b, aux);
		else
			action_pa(s);
		aux[1]++;
		ft_free(f);
	}
	while (aux[2] >= 0)
	{
		action_rx(s->stack_a, NULL, s->size, 'a');
		aux[2]--;
	}
}

static void	half_to_b(t_stacks *s, int time)
{
	int	x;
	int	middle;

	x = 0;
	middle = to_binary(s->size / 2);
	while (x < s->size / 2)
	{
		if (time == 1 && ft_atoi(s->stack_a[0]) < middle)
		{
			action_pb(s);
			x++;
		}
		else if (time == 2 && ft_atoi(s->stack_a[0]) >= middle)
		{
			action_pb(s);
			x++;
		}
		else
			action_rx(s->stack_a, NULL, s->size - x, 'a');
	}
}

void	optimized_insert_sort(t_stacks *s)
{
	t_stacks	f;

	half_to_b(s, 1);
	back_to_a(s, &f);
	half_to_b(s, 2);
	back_to_a(s, &f);
}
