/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:29:36 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/05 23:13:34 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_duplicates(char *argv[], int size)
{
	int	x;
	int	y;
	int	aux;

	x = 1;
	while (x < size)
	{
		aux = ft_atoi(argv[x]);
		y = x + 1;
		while (y < size)
		{
			if (ft_atoi(argv[y]) == aux)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	check_args(char *argv[], int size)
{
	int	x;
	int	y;

	x = 1;
	while (x < size)
	{
		y = 0;
		while (argv[x][y])
		{
			if (!ft_isdigit(argv[x][y])
				&& argv[x][y] != '-' && argv[x][y] != '+')
				return (0);
			if (!ft_isdigit(argv[x][y]) && y != 0)
				return (0);
			y++;
		}
		x++;
	}
	return (check_duplicates(argv, size));
}
