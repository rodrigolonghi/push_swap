/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:47:09 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/12 01:50:52 by rfelipe-         ###   ########.fr       */
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

static int	get_args_number(int argc, char **argv)
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

int	main(int argc, char **argv)
{
	int			n_args;
	char		**args;
	t_stacks	*s;

	n_args = get_args_number(argc, argv);
	if (argc == 2 && !ft_strchr(argv[1], 32))
		argc = 3;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	if ((argc == 2 && check_args(n_args, args, argc))
		|| (argc > 2 && check_args(n_args, argv + 1, argc)))
	{
		s = ft_calloc(1, sizeof(t_stacks));
		if (argc == 2)
			create_stack(n_args, args, s, argc);
		else
			create_stack(n_args, argv + 1, s, argc);
		if (check_is_sorted(s) == 0)
			sorter(s);
		put_moves(s);
		free_stack(s);
	}
	else
		throw_error();
	return (0);
}
