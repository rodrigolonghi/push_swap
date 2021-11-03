/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_quick_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:51:02 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/02 22:31:52 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	change_position_data(int *position, int x, t_stacks *s)
{
	position[0] += s->size / x;
	position[2] += s->size / x;
	position[1] = (position[0] + position[2]) / 2;
}

static void	to_a(int *aux, t_stacks *s, int *moves)
{
	t_stacks	f;

	aux[0] = find_index(s->stack_b, s->size, aux[2] - 1);
	aux[1] = find_index(s->stack_b, s->size, aux[2] - 2);
	duplicate_stack(&f, s);
	if (aux[2] > 1 && fake_to_top(f.stack_b, f.size, aux[0])
		< fake_to_top(f.stack_b, f.size, aux[1]))
	{
		moves[0] += fake_to_top(s->stack_b, s->size, aux[0]);
		moves[0] += fake_action_pa(s);
	}
	else if (aux[2] > 1)
	{
		moves[0] += fake_to_top(s->stack_b, s->size, aux[1]);
		moves[0] += fake_action_pa(s);
		moves[0] += fake_to_top(s->stack_b, s->size, find_index(s->stack_b,
					s->size, aux[2] - 1));
		moves[0] += fake_action_pa(s);
		moves[0] += fake_action_sx(s->stack_a, NULL);
		aux[2]--;
	}
	if (aux[2] == 1)
		moves[0] += fake_action_pa(s);
	free_stack(&f);
}

static void	to_b(t_stacks *s, int *aux, int *position, int *moves)
{
	t_stacks	f;

	duplicate_stack(&f, s);
	find_top_and_bottom(aux, s, position[0], position[2]);
	if (fake_to_top(f.stack_a, f.size, aux[0])
		< fake_to_top(f.stack_a, f.size, aux[1]))
		moves[0] += fake_to_top(s->stack_a, s->size, aux[0]);
	else
		moves[0] += fake_to_top(s->stack_a, s->size, aux[1]);
	moves[0] += fake_action_pb(s);
	if (find_relative_size(s->stack_b, s->size) > 1
		&& ft_atoi(s->stack_b[0]) < position[1])
		moves[0] += fake_action_rx(s->stack_b, NULL, s->size);
	free_stack(&f);
}

void	fake_quick_sort(t_stacks *s, int x, int *moves)
{
	int	*aux;
	int	*position;

	aux = ft_calloc(3, sizeof(int));
	position = ft_calloc(3, sizeof(int));
	position[1] = s->size / x / 2;
	position[2] = s->size / x;
	while (aux[2] < s->size)
	{
		to_b(s, aux, position, moves);
		aux[2]++;
		if (aux[2] == position[2])
			change_position_data(position, x, s);
	}
	aux[2] = s->size;
	while (aux[2] > 0)
	{
		to_a(aux, s, moves);
		aux[2]--;
	}
	free(aux);
	free(position);
}
