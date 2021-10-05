/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:33:29 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/10/04 23:17:41 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

void	throw_error(char *msg);
void	create_stacks(int *stackA, int size, char *args[]);
int		check_args(char *argv[], int size);

#endif
