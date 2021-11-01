/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:33:32 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/26 20:59:15 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	throw_error(t_stacks *s)
{
	ft_putendl_fd("Error", 2);
	free_stack(s);
	exit(1);
}

void	create_args(int argc, char **argv, t_stacks *s)
{
	int	x;

	if (argc == 2)
		s->args = ft_split(argv[1], ' ');
	else
	{
		x = 0;
		while (x < s->size)
		{
			s->args[x] = argv[x + 1];
			x++;
		}
	}
	if (s->size <= 5)
	{
		s->moves = 15;
		s->moves_list = ft_calloc(s->moves, sizeof(char *));
	}
}

int	get_args_number(char **argv, int argc)
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
	t_stacks	s;

	s.size = get_args_number(argv, argc);
	if (s.size > 0)
	{
		s.args = ft_calloc(s.size, sizeof(char *));
		create_args(argc, argv, &s);
		if (check_args(&s) == 1)
		{
			s.stack_a = ft_calloc(s.size + 1, sizeof(char *));
			s.stack_b = ft_calloc(s.size + 1, sizeof(char *));
			create_stacks(&s);
			if (check_is_sorted(&s) == 0)
			{
				sorter(&s);
				put_moves(&s);
			}
		}
		else
			throw_error(&s);
	}
	free_stack(&s);
	exit(0);
	return (0);
}
