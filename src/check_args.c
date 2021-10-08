/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:29:36 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/07 22:30:46 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_duplicates(char **args, int size)
{
	int	x;
	int	y;
	int	aux;

	x = 0;
	while (x < size)
	{
		aux = ft_atoi(args[x]);
		y = x + 1;
		while (y < size)
		{
			if (ft_atoi(args[y]) == aux)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	check_args(char **args, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (args[x][y])
		{
			if (!ft_isdigit(args[x][y])
				&& args[x][y] != '-' && args[x][y] != '+')
				throw_error("Invalid arguments!\n");
			if (!ft_isdigit(args[x][y]) && y != 0)
				throw_error("Invalid arguments!\n");
			y++;
		}
		x++;
	}
	if (check_duplicates(args, size) == 0)
		throw_error("There are duplicate numbers!\n");
}
