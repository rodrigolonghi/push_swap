/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:50:37 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/01 04:38:13 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simulate(t_stacks *s, int aux)
{
	int			*quick_moves;
	t_stacks	f;

	quick_moves = ft_calloc(1, sizeof(int));
	duplicate_stack(&f, s);
	fake_quick_sort(&f, aux, quick_moves);
	free_stack(&f);
	s->moves = quick_moves[0];
	s->moves_list = ft_calloc(s->moves + 1, sizeof(char *));
	free(quick_moves);
}
