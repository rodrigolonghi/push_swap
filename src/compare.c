/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 01:59:12 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/10 17:48:26 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compare(char *a, char *b)
{
	if (ft_atoi(a) > ft_atoi(b))
		return (1);
	else if (ft_atoi(a) < ft_atoi(b))
		return (-1);
	return (0);
}
