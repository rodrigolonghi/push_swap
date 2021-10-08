/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 00:25:48 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/08 00:38:28 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace(void *content, int a, int b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)content)[i] == (unsigned char)a)
			((unsigned char *)content)[i] = (unsigned char)b;
		i++;
	}
}
