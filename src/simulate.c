/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:50:37 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/24 20:01:46 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	simulate(t_stacks *s)
{
	int			*insert_moves;
	int			*radix_moves;
	t_stacks	f;

	insert_moves = ft_calloc(1, sizeof(int));
	radix_moves = ft_calloc(1, sizeof(int));
	duplicate_stack(&f, s);
	fake_insert_sort(&f, insert_moves);
	free_stack(&f);
	duplicate_stack(&f, s);
	fake_radix_sort(&f, radix_moves);
	free_stack(&f);
	if (insert_moves < radix_moves)
		return (1);
	return (2);
}
