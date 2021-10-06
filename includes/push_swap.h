/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:33:29 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/06 03:30:59 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>

void	throw_error(char *msg);
void	create_stacks(char **stack, int size, char *args[]);
int		check_args(char *argv[], int size);
void	action_sx(char **stack, char **stackOptional, char c);
void	action_rx(char **stack, char **stackOptional, int size, char c);
void	action_rrx(char **stack, char **stackOptional, int size, char c);
void	action_pa(char **stackA, char **stackB, int size);
void	action_pb(char **stackA, char **stackB, int size);
int		check_is_sorted(char **stack, int size);
void	sorter(char **stack_a, char **stack_b, int size);
void	case_three(char **stack, char c);
void	case_five(char **stack_a, char **stack_b, int size);
void	general_case(char **stack_a, char **stack_b, int size);
int		compare(char *a, char *b);

#endif
