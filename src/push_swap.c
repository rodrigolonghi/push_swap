/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:33:32 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/09 03:18:28 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(char **stack_a, char **stack_b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack_a[i] != NULL)
			ft_putstr_fd(stack_a[i], 1);
		else
			ft_putchar_fd('_', 1);
		ft_putchar_fd('	', 1);
		if (stack_b[i] != NULL)
			ft_putendl_fd(stack_b[i], 1);
		else
			ft_putendl_fd("_", 1);
		i++;
	}
}

static void	ft_free(char **stack_a, char **stack_b, char **args)
{
	free(stack_a);
	free(stack_b);
	free(args);
}

void	set_args(char **args, char **argv, int argc, int size)
{
	int	x;

	x = 0;
	if (argc != 2)
	{
		while (x < size)
		{
			args[x] = argv[x + 1];
			x++;
		}
	}
	check_args(args, size);
}

int	get_args(char **argv, int argc)
{
	int	n_args;
	int	x;

	n_args = 0;
	x = 0;
	if (argc == 2)
	{
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
	}
	if (argc == 2)
		return (n_args);
	return (argc - 1);
}

int	main(int argc, char **argv)
{
	char	**stack_a;
	char	**stack_b;
	char	**args;
	int		size;

	size = get_args(argv, argc);
	if (argc < 2)
		throw_error("Invalid number of arguments!\n");
	if (argc == 2)
	{
		args = ft_calloc(size + 1, sizeof(char *));
		ft_replace(argv[1], '	', ' ', ft_strlen(argv[1]));
		args = ft_split(argv[1], ' ');
	}
	else
		args = ft_calloc(argc, sizeof(char *));
	set_args(args, argv, argc, size);
	stack_a = ft_calloc(size + 1, sizeof(char *));
	create_stacks(stack_a, size, args);
	stack_b = ft_calloc(size + 1, sizeof(char *));
	if (check_is_sorted(stack_a, size) == 0)
		sorter(stack_a, stack_b, size);
	ft_free(stack_a, stack_b, args);
	exit(EXIT_SUCCESS);
	return (0);
}
