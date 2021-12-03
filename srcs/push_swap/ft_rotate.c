/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:09:03 by chduong           #+#    #+#             */
/*   Updated: 2021/11/19 17:08:07 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static void	rotate(t_list **first)
{
	if (!first || !*first)
		return ;
	*first = (*first)->next;
}

void	rotate_a(t_list **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_list **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_2(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
