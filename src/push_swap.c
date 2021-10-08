/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:33:32 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/07 22:58:18 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int		n_args;
	char	*aux;
	char	*temp;

	n_args = 1;
	temp = ft_strchr(argv[1], ' ');
	aux = temp + 1;
	while (aux != NULL && argc == 2)
	{
		aux = ft_strchr(temp + 1, ' ');
		if (aux != NULL)
			temp = aux + 1;
		n_args++;
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
		args = ft_split(argv[1], ' ');
	}
	else
		args = ft_calloc(argc, sizeof(char *));
	set_args(args, argv, argc, size);
	stack_a = ft_calloc(size + 1, sizeof(char *));
	create_stacks(stack_a, size, args);
	stack_b = ft_calloc(size + 1, sizeof(char *));
	sorter(stack_a, stack_b, size);
	ft_free(stack_a, stack_b, args);
	return (0);
}
