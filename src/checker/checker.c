/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:34:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/18 20:13:19 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	auxiliary(int argc, char **args, char **argv, int n_args)
{
	char		*line;
	t_list		*i;
	t_stacks	*s;

	i = NULL;
	s = ft_calloc(1, sizeof(t_stacks));
	if (argc == 2)
		create_stack(n_args, args, s, argc);
	else
		create_stack(n_args, argv + 1, s, argc);
	while (get_next_line(0, &line) == 1)
	{
		check_instruction(line, i, s);
		ft_lstadd_back(&i, ft_lstnew(line));
	}
	check_sorter(s, i);
	free_all(s, i);
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
		throw_error();
	return (0);
}
