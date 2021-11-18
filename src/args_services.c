/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_services.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:21:16 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/13 23:21:43 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	verify_arg(char *arg)
{
	int	x;

	x = 0;
	while (x < ft_strlen(arg))
	{
		if (!ft_isdigit(arg[x]) && arg[x] != '-'
			&& arg[x] != '+' && arg[x] != 32)
			throw_error();
		x++;
	}
}

void	free_args(int n_args, char **args, int argc)
{
	int	x;

	if (argc == 2)
	{
		x = 0;
		while (x < n_args)
		{
			if (args[x] != NULL)
				free(args[x]);
			x++;
		}
		if (args != NULL)
			free(args);
	}
}

int	get_args_number(int argc, char **argv)
{
	int	n_args;
	int	x;

	n_args = 0;
	x = 0;
	if (argc == 2)
	{
		verify_arg(argv[1]);
		while (x < (int)ft_strlen(argv[1]))
		{
			if (argv[1][x] > 32)
			{
				while (argv[1][x] > 32)
					x++;
				n_args++;
			}
			x++;
		}
		return (n_args);
	}
	return (argc - 1);
}
