/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:24:29 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/04/03 00:15:32 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_is_sorted(t_stacks *s)
{
	int	x;
	int	y;
	int	aux;
	int	size;

	size = get_relative_size(s->stack_b, s->size);
	if (size > 0)
		return (0);
	x = 0;
	size = get_relative_size(s->stack_a, s->size);
	while (x < size)
	{
		aux = s->stack_a[x];
		y = x + 1;
		while (y < size)
		{
			if (aux > s->stack_a[y])
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

static int	check_duplicates(int n_args, char **args, int argc)
{
	int	x;
	int	y;
	int	aux;

	x = 0;
	while (x < n_args)
	{
		aux = ft_atoi(args[x]);
		y = x + 1;
		while (y < n_args)
		{
			if (ft_atoi(args[y]) == aux)
			{
				if (argc == 2)
					free_args(n_args, args, argc);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

static int	check_nbr_limit(char *arg)
{
	if (ft_strlen(arg) == 10 && ft_memcmp("2147483647", arg, 10) < 0)
		return (0);
	else if (ft_strlen(arg) == 11 && ft_memcmp("-2147483648", arg, 11) < 0)
		return (0);
	else if (ft_strlen(arg) > 11)
		return (0);
	return (1);
}

int	check_args(int n_args, char **args, int argc)
{
	int	x;
	int	y;

	x = 0;
	while (x < n_args)
	{
		verify_arg(args[x]);
		if (!check_nbr_limit(args[x]))
			return (0);
		y = 0;
		while (args[x][y])
		{
			if (!ft_isdigit(args[x][y])
				&& args[x][y] != '-' && args[x][y] != '+')
				return (0);
			if (!ft_isdigit(args[x][y]) && y != 0)
				return (0);
			if (ft_memcmp("-", args[x], ft_strlen(args[x])) == 0
				|| ft_memcmp("+", args[x], ft_strlen(args[x])) == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (check_duplicates(n_args, args, argc));
}
