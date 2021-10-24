/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:52:30 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/24 19:52:58 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_to_binary(int nbr)
{
	int	aux;
	int	exp;

	aux = 0;
	exp = 0;
	while (nbr != 0)
	{
		if (exp > 0)
			aux += nbr % 2 * exp;
		else
			aux = nbr % 2;
		nbr /= 2;
		if (exp == 0)
			exp = 10;
		else
			exp *= 10;
	}
	return (aux);
}
