/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:29:36 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/24 19:12:53 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_is_sorted(t_stacks *s)
{
	int	x;
	int	y;

	x = 0;
	while (x < s->size - 1 && s->stack_a[x] != NULL)
	{
		y = x + 1;
		while (y < s->size && s->stack_a[y] != NULL)
		{
			if (ft_atoi(s->stack_a[x]) > ft_atoi(s->stack_a[y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	check_nbr_limit(t_stacks *s)
{
	int		x;

	x = 0;
	while (x < s->size)
	{
		if (ft_strlen(s->args[x]) == 10)
		{
			if (ft_memcmp("2147483647", s->args[x], 10) < 0)
				return (0);
		}
		else if (ft_strlen(s->args[x]) == 11)
		{
			if (ft_memcmp("-2147483648", s->args[x], 11) < 0)
				return (0);
		}
		else if (ft_strlen(s->args[x]) > 11)
			return (0);
		x++;
	}
	return (1);
}

int	check_duplicates(t_stacks *s)
{
	int	x;
	int	y;
	int	aux;

	x = 0;
	while (x < s->size)
	{
		aux = ft_atoi(s->args[x]);
		y = x + 1;
		while (y < s->size)
		{
			if (ft_atoi(s->args[y]) == aux)
				return (0);
			y++;
		}
		x++;
	}
	return (check_nbr_limit(s));
}

int	check_args(t_stacks *s)
{
	int	x;
	int	y;

	x = 0;
	while (x < s->size)
	{
		y = 0;
		while (s->args[x][y])
		{
			if (!ft_isdigit(s->args[x][y])
				&& s->args[x][y] != '-' && s->args[x][y] != '+')
				return (0);
			if (!ft_isdigit(s->args[x][y]) && y != 0)
				return (0);
			if (ft_memcmp("-", s->args[x], ft_strlen(s->args[x])) == 0
				|| ft_memcmp("+", s->args[x], ft_strlen(s->args[x])) == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (check_duplicates(s));
}
