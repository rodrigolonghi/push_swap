/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:12:21 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/04 20:14:11 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	throw_error(char *msg)
{
	ft_putendl_fd("Error", 1);
	ft_putstr_fd(msg, 1);
	exit(0);
}
