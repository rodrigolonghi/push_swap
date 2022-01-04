/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:47:09 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/01/04 19:19:34 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	check_exit(int argc)
{
	if (argc == 1)
		exit(0);
	throw_error();
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
		check_exit(argc);
	return (0);
}
