/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:33:32 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/04 23:24:32 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	*stackA;
	int	*stackB;

	if (argc < 3)
		throw_error("Invalid number of arguments!\n");
	else if (check_args(argv, argc))
	{
		stackA = ft_calloc(argc - 1, sizeof(int));
		stackB = ft_calloc(argc - 1, sizeof(int));
		create_stacks(stackA, argc - 1, argv);
	}
	else
		throw_error("Invalid arguments!\n");
	return (0);
}
