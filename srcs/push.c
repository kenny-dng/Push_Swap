/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennyduong <kennyduong@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:08:39 by chduong           #+#    #+#             */
/*   Updated: 2021/11/17 18:35:59 by kennyduong       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*move;

	if (*b)
	{
		move = *b;
		*b = (*b)->next;
		ft_lstadd_front(a, move);
		ft_putstr_fd("pa\n", 1);
	}
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*move;

	if (*a)
	{
		move = *a;
		*a = (*a)->next;
		ft_lstadd_front(b, move);
		ft_putstr_fd("pb\n", 1);
	}
}
