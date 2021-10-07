/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:33:32 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/06 21:22:15 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	char	**stack_a;
	char	**stack_b;

	if (argc < 3)
		throw_error("Invalid number of arguments!\n");
	else if (check_args(argv, argc))
	{
		stack_a = ft_calloc(argc, sizeof(char *));
		create_stacks(stack_a, argc - 1, argv);
		stack_b = ft_calloc(argc, sizeof(char *));
		sorter(stack_a, stack_b, argc - 1);
	}
	else
		throw_error("Invalid arguments!\n");
	return (0);
}
