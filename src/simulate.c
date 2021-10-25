/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:50:37 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/25 02:15:26 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	smaller_option(int *insert, int *radix, int *custom, int *moves)
{
	if (insert[0] < radix[0] && insert[0] < custom[0])
		moves[0] = insert[0];
	else if (radix[0] < insert[0] && radix[0] < custom[0])
		moves[0] = radix[0];
	else if (custom[0] < insert[0] && custom[0] < radix[0])
		moves[0] = custom[0];
	else if (insert[0] < radix[0] && insert[0] == custom[0])
		moves[0] = custom[0];
	else if (insert[0] < custom[0] && insert[0] == radix[0])
		moves[0] = radix[0];
	else if (radix[0] < insert[0] && radix[0] == custom[0])
		moves[0] = custom[0];
	else
		moves[0] = custom[0];
}

static int	best_option(int *insert, int *radix, int *custom)
{
	if (insert[0] < radix[0] && insert[0] < custom[0])
		return (1);
	else if (radix[0] < insert[0] && radix[0] < custom[0])
		return (2);
	else if (custom[0] < insert[0] && custom[0] < radix[0])
		return (3);
	else if (insert[0] < radix[0] && insert[0] == custom[0])
		return (3);
	else if (insert[0] < custom[0] && insert[0] == radix[0])
		return (2);
	else if (radix[0] < insert[0] && radix[0] == custom[0])
		return (3);
	return (3);
}

int	simulate(t_stacks *s)
{
	int			*insert_moves;
	int			*radix_moves;
	int			*custom_moves;
	t_stacks	f;

	insert_moves = ft_calloc(1, sizeof(int));
	radix_moves = ft_calloc(1, sizeof(int));
	custom_moves = ft_calloc(1, sizeof(int));
	duplicate_stack(&f, s);
	fake_insert_sort(&f, insert_moves);
	if (check_is_sorted(&f) == 0)
		insert_moves[0] = 2147483647;
	duplicate_stack(&f, s);
	fake_radix_sort(&f, radix_moves);
	if (check_is_sorted(&f) == 0)
		radix_moves[0] = 2147483647;
	duplicate_stack(&f, s);
	fake_custom_sort(&f, custom_moves);
	if (check_is_sorted(&f) == 0)
		custom_moves[0] = 2147483647;
	free_stack(&f);
	smaller_option(insert_moves, radix_moves, custom_moves, &s->moves);
	return (best_option(insert_moves, radix_moves, custom_moves));
}
