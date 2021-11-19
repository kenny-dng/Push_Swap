/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennyduong <kennyduong@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:09:03 by chduong           #+#    #+#             */
/*   Updated: 2021/11/17 18:36:13 by kennyduong       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_list **first)
{
	t_list	*last;
	t_list	*plast;

	if (!first || !*first)
		return ;
	last = ft_lstlast(*first);
	last->next = *first;
	plast = *first;
	while (plast->next != last)
		plast = plast->next;
	plast->next = NULL;
	*first = last;
}

void	rrotate_a(t_list **a)
{
	rrotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrotate_b(t_list **b)
{
	rrotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrotate_2(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
	ft_putstr_fd("rrr\n", 1);
}
