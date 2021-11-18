/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_services.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:39:00 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/13 23:55:40 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_instruction(char *line, t_list *i, t_stacks *s)
{
	int	len;

	len = ft_strlen(line);
	if (ft_memcmp("sa", line, len) != 0 && ft_memcmp("sb", line, len) != 0
		&& ft_memcmp("ss", line, len) != 0 && ft_memcmp("ra", line, len) != 0
		&& ft_memcmp("rb", line, len) != 0 && ft_memcmp("rr", line, len) != 0
		&& ft_memcmp("rra", line, len) != 0 && ft_memcmp("rrb", line, len) != 0
		&& ft_memcmp("rrr", line, len) != 0 && ft_memcmp("pa", line, len) != 0
		&& ft_memcmp("pb", line, len) != 0)
	{
		free_all(s, i);
		throw_error();
	}
	if (ft_memcmp("sa", line, 2) != 0 && ft_memcmp("sb", line, 2) != 0
		&& ft_memcmp("ss", line, 2) != 0 && ft_memcmp("ra", line, 2) != 0
		&& ft_memcmp("rb", line, 2) != 0 && ft_memcmp("rr", line, 2) != 0
		&& ft_memcmp("rra", line, 3) != 0 && ft_memcmp("rrb", line, 3) != 0
		&& ft_memcmp("rrr", line, 3) != 0 && ft_memcmp("pa", line, 2) != 0
		&& ft_memcmp("pb", line, 2) != 0)
	{
		free_all(s, i);
		throw_error();
	}
}
