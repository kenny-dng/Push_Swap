/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:09:03 by chduong           #+#    #+#             */
/*   Updated: 2021/11/19 17:09:19 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_list **first)
{
	if (!first || !*first)
		return ;
	*first = (*first)->prev;
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
