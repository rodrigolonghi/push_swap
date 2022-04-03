/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:34:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/04/02 22:53:16 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	check_exit(int argc)
{
	if (argc == 1)
		exit(0);
	throw_error();
}

static int	parse_instruction(char *line, int len_line)
{
	if (ft_memcmp("sa", line, len_line) == 0)
		return (0);
	else if (ft_memcmp("sb", line, len_line) == 0)
		return (1);
	else if (ft_memcmp("ss", line, len_line) == 0)
		return (2);
	else if (ft_memcmp("ra", line, len_line) == 0)
		return (3);
	else if (ft_memcmp("rb", line, len_line) == 0)
		return (4);
	else if (ft_memcmp("rr", line, len_line) == 0)
		return (5);
	else if (ft_memcmp("rra", line, len_line) == 0)
		return (6);
	else if (ft_memcmp("rrb", line, len_line) == 0)
		return (7);
	else if (ft_memcmp("rrr", line, len_line) == 0)
		return (8);
	else if (ft_memcmp("pa", line, len_line) == 0)
		return (9);
	else if (ft_memcmp("pb", line, len_line) == 0)
		return (10);
	else
		return (-1);
}

static int	*save_instruction(int *inst, char *line, int size)
{
	int	x;
	int	*aux;

	x = 0;
	aux = malloc((size + 1) * sizeof(int));
	while (x < size)
	{
		aux[x] = inst[x];
		x++;
	}
	aux[x] = parse_instruction(line, ft_strlen(line));
	if (size > 0)
		free(inst);
	inst = malloc((size + 1) * sizeof(int));
	x = 0;
	while (x <= size)
	{
		inst[x] = aux[x];
		x++;
	}
	free(aux);
	return (inst);
}

static void	auxiliary(int argc, char **args, char **argv, int n_args)
{
	int			*inst;
	int			size;
	char		*line;
	t_stacks	*s;

	s = ft_calloc(1, sizeof(t_stacks));
	if (argc == 2)
		create_stack(n_args, args, s, argc);
	else
		create_stack(n_args, argv + 1, s, argc);
	size = 0;
	while (get_next_line(0, &line) == 1)
	{
		inst = save_instruction(inst, line, size);
		check_instruction(line, inst, s);
		free(line);
		size++;
	}
	check_sorter(s, inst, size);
	free_all(s, inst);
}

int	main(int argc, char **argv)
{
	int		n_args;
	char	**args;

	n_args = get_args_number(argc, argv);
	if (n_args == 1)
		exit(0);
	if (argc == 2 && !ft_strchr(argv[1], 32))
		argc = 3;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	if ((argc == 2 && check_args(n_args, args, argc))
		|| (argc > 2 && check_args(n_args, argv + 1, argc)))
		auxiliary(argc, args, argv, n_args);
	else
		check_exit(argc);
	return (0);
}
