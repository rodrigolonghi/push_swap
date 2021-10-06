/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:05:15 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/06 00:40:07 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	// int		i;
	// char	**stack_a;
	// char	**stack_b;

	if (argc == 1 || argv[0] == NULL)
		throw_error("Invalid number of arguments!\n");
	else
	{
		printf("%d\n", argc);
	}
	return (0);
}
