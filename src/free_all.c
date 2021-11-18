/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:15:03 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/13 22:59:19 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_stacks *s, t_list *list)
{
	t_list	*p;

	free_stack(s);
	p = list;
	while (p != NULL)
	{
		list = list->next;
		free(p);
		p = list;
	}
}
