/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:24:46 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/12 19:24:49 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	change_position_data(int *position, int x, t_stacks *s)
{
	position[0] += s->size / x;
	position[2] += s->size / x;
	position[1] = (position[0] + position[2]) / 2;
}

static void	to_a(int *aux, t_stacks *s)
{
	t_stacks	*f;

	aux[0] = find_index(s->stack_b, s->size, aux[2]);
	aux[1] = find_index(s->stack_b, s->size, aux[2] - 1);
	f = malloc(sizeof(t_stacks));
	duplicate_stack(f, s);
	if (aux[2] > 1 && fake_to_top(f->stack_b, f, aux[0])
		< fake_to_top(f->stack_b, f, aux[1]))
	{
		to_top(s->stack_b, s, aux[0], 'b');
		action_pa(s);
	}
	else if (aux[2] > 1)
	{
		to_top(s->stack_b, s, aux[1], 'b');
		action_pa(s);
		to_top(s->stack_b, s, find_index(s->stack_b, s->size, aux[2]), 'b');
		action_pa(s);
		action_sx(s->stack_a, NULL, s, 'a');
		aux[2]--;
	}
	else if (aux[2] == 1)
		action_pa(s);
	free_stack(f);
}

static void	to_b(t_stacks *s, int *aux, int *position)
{
	t_stacks	*f;

	f = malloc(sizeof(t_stacks));
	duplicate_stack(f, s);
	find_top_and_bottom(aux, s, position[0], position[2]);
	if (fake_to_top(f->stack_a, f, aux[0]) < fake_to_top(f->stack_a, f, aux[1]))
		to_top(s->stack_a, s, aux[0], 'a');
	else
		to_top(s->stack_a, s, aux[1], 'a');
	action_pb(s);
	if (get_relative_size(s->stack_b, s->size) > 1
		&& s->stack_b[0] < position[1])
		action_rx(s->stack_b, NULL, s, 'b');
	free_stack(f);
}

void	quick_sort(t_stacks *s, int pivot)
{
	int	*aux;
	int	*position;

	aux = ft_calloc(3, sizeof(int));
	position = ft_calloc(3, sizeof(int));
	position[0] = 1;
	position[1] = s->size / pivot / 2;
	position[2] = s->size / pivot + 1;
	while (aux[2] < s->size)
	{
		to_b(s, aux, position);
		aux[2]++;
		if (aux[2] == position[2] - 1)
			change_position_data(position, pivot, s);
	}
	aux[2] = s->size;
	while (aux[2] > 0)
	{
		to_a(aux, s);
		aux[2]--;
	}
	free(aux);
	free(position);
}
