/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_service.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:44:41 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/01 04:36:48 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clean_moves(t_stacks *s, char **action, int l)
{
	int	x;

	x = 0;
	while (x < s->moves)
	{
		if (s->moves_list[x] && ft_memcmp(s->moves_list[x], action[0], l) == 0)
		{
			if (s->moves_list[x + 1]
				&& ft_memcmp(s->moves_list[x + 1], action[1], l) == 0)
			{
				s->moves_list[x] = action[2];
				s->moves_list[x + 1] = NULL;
			}
		}
		x++;
	}
}

static void	clean_helper(t_stacks *s)
{
	char	**action;

	action = ft_calloc(3, sizeof(char *));
	action[0] = "sa";
	action[1] = "sb";
	action[2] = "ss";
	clean_moves(s, action, 2);
	action[0] = "sb";
	action[1] = "sa";
	clean_moves(s, action, 2);
	action[0] = "ra";
	action[1] = "rb";
	action[2] = "rr";
	clean_moves(s, action, 2);
	action[0] = "rb";
	action[1] = "ra";
	clean_moves(s, action, 2);
	action[0] = "rra";
	action[1] = "rrb";
	action[2] = "rrr";
	clean_moves(s, action, 3);
	action[0] = "rrb";
	action[1] = "rra";
	clean_moves(s, action, 3);
	free(action);
}

void	put_moves(t_stacks *s)
{
	int		x;

	clean_helper(s);
	x = 0;
	while (x < s->moves)
	{
		if (s->moves_list[x] != NULL)
			ft_putendl_fd(s->moves_list[x], 1);
		x++;
	}
}

void	write_next_move(t_stacks *s, char *move)
{
	int	x;

	x = 0;
	while (s->moves_list[x] != NULL)
		x++;
	s->moves_list[x] = move;
}
