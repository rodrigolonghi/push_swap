/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:57:37 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/04/02 20:01:28 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_action(t_stacks *s, t_list *i)
{
	int	len;

	len = ft_strlen(i->content);
	if (ft_memcmp("sa", i->content, len) == 0)
		fake_action_sx(s->stack_a, NULL, s);
	else if (ft_memcmp("sb", i->content, len) == 0)
		fake_action_sx(s->stack_b, NULL, s);
	else if (ft_memcmp("ss", i->content, len) == 0)
		fake_action_sx(s->stack_a, s->stack_b, s);
	else if (ft_memcmp("ra", i->content, len) == 0)
		fake_action_rx(s->stack_a, NULL, s);
	else if (ft_memcmp("rb", i->content, len) == 0)
		fake_action_rx(s->stack_b, NULL, s);
	else if (ft_memcmp("rr", i->content, len) == 0)
		fake_action_rx(s->stack_a, s->stack_b, s);
	else if (ft_memcmp("rra", i->content, len) == 0)
		fake_action_rrx(s->stack_a, NULL, s);
	else if (ft_memcmp("rrb", i->content, len) == 0)
		fake_action_rrx(s->stack_b, NULL, s);
	else if (ft_memcmp("rrr", i->content, len) == 0)
		fake_action_rrx(s->stack_a, s->stack_b, s);
	else if (ft_memcmp("pa", i->content, len) == 0)
		fake_action_pa(s);
	else if (ft_memcmp("pb", i->content, len) == 0)
		fake_action_pb(s);
}

void	check_sorter(t_stacks *s, t_list *i)
{
	int	x;
	int	size;

	size = ft_lstsize(i);
	x = 0;
	while (x < size)
	{
		do_action(s, i);
		i = i->next;
		x++;
	}
	if (check_is_sorted(s))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
