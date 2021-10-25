/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_service.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:44:41 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/25 20:20:01 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clean_moves(t_stacks *s, char **action, int l, char c)
{
	int	x;
	int	y;

	x = 0;
	while (x < s->moves)
	{
		if (s->moves_list[x] && ft_memcmp(s->moves_list[x], action[0], l) == 0)
		{
			y = x + 1;
			while (y < s->moves && ft_memcmp(s->moves_list[y], action[0], l))
			{
				if (s->moves_list[y] && ft_strchr(s->moves_list[y], c))
				{
					if (ft_memcmp(s->moves_list[y], action[1], 2) == 0)
					{
						s->moves_list[x] = action[2];
						s->moves_list[y] = NULL;
					}
					break ;
				}
				y++;
			}
		}
		x++;
	}
}

static void	clean_helper(t_stacks *s)
{
	int		count_moves;
	char	**action;

	count_moves = 0;
	while (count_moves < s->moves && s->moves_list[count_moves])
		count_moves++;
	s->moves = count_moves;
	action = ft_calloc(3, sizeof(char *));
	action[0] = "sa";
	action[1] = "sb";
	action[2] = "ss";
	clean_moves(s, action, 2, 'b');
	action[0] = "ra";
	action[1] = "rb";
	action[2] = "rr";
	clean_moves(s, action, 2, 'b');
	action[0] = "rra";
	action[1] = "rrb";
	action[2] = "rrr";
	clean_moves(s, action, 3, 'b');
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
	s->moves_list[x] = ft_strjoin(move, "\0");
}
