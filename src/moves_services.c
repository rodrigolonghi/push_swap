/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_services.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:34:29 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/12 18:59:19 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	clean_moves(t_stacks *s, int first_move, int second_move, int match)
{
	int	x;

	x = 0;
	while (x < s->moves)
	{
		if (s->moves_list[x] != 0 && s->moves_list[x] == first_move)
		{
			if (s->moves_list[x + 1] != 0
				&& s->moves_list[x + 1] == second_move)
			{
				s->moves_list[x] = match;
				s->moves_list[x + 1] = 0;
			}
		}
		x++;
	}
}

static void	clean_helper(t_stacks *s)
{
	clean_moves(s, 1, 2, 3);
	clean_moves(s, 2, 1, 3);
	clean_moves(s, 4, 5, 6);
	clean_moves(s, 5, 4, 6);
	clean_moves(s, 7, 8, 9);
	clean_moves(s, 8, 7, 9);
}

static void	print_moves(int move)
{
	if (move == 1)
		ft_putstr_fd("sa\n", 1);
	else if (move == 2)
		ft_putstr_fd("sb\n", 1);
	else if (move == 3)
		ft_putstr_fd("ss\n", 1);
	else if (move == 4)
		ft_putstr_fd("ra\n", 1);
	else if (move == 5)
		ft_putstr_fd("rb\n", 1);
	else if (move == 6)
		ft_putstr_fd("rr\n", 1);
	else if (move == 7)
		ft_putstr_fd("rra\n", 1);
	else if (move == 8)
		ft_putstr_fd("rrb\n", 1);
	else if (move == 9)
		ft_putstr_fd("rrr\n", 1);
	else if (move == 10)
		ft_putstr_fd("pa\n", 1);
	else if (move == 11)
		ft_putstr_fd("pb\n", 1);
}

void	put_moves(t_stacks *s)
{
	int	x;

	clean_helper(s);
	x = 0;
	while (x < s->moves)
	{
		print_moves(s->moves_list[x]);
		x++;
	}
}

void	save_next_move(t_stacks *s, char *move)
{
	int	size;

	size = get_relative_size(s->moves_list, s->moves);
	if (ft_memcmp(move, "sa", ft_strlen(move)) == 0)
		s->moves_list[size] = 1;
	else if (ft_memcmp(move, "sb", ft_strlen(move)) == 0)
		s->moves_list[size] = 2;
	else if (ft_memcmp(move, "ss", ft_strlen(move)) == 0)
		s->moves_list[size] = 3;
	else if (ft_memcmp(move, "ra", ft_strlen(move)) == 0)
		s->moves_list[size] = 4;
	else if (ft_memcmp(move, "rb", ft_strlen(move)) == 0)
		s->moves_list[size] = 5;
	else if (ft_memcmp(move, "rr", ft_strlen(move)) == 0)
		s->moves_list[size] = 6;
	else if (ft_memcmp(move, "rra", ft_strlen(move)) == 0)
		s->moves_list[size] = 7;
	else if (ft_memcmp(move, "rrb", ft_strlen(move)) == 0)
		s->moves_list[size] = 8;
	else if (ft_memcmp(move, "rrr", ft_strlen(move)) == 0)
		s->moves_list[size] = 9;
	else if (ft_memcmp(move, "pa", ft_strlen(move)) == 0)
		s->moves_list[size] = 10;
	else if (ft_memcmp(move, "pb", ft_strlen(move)) == 0)
		s->moves_list[size] = 11;
}
