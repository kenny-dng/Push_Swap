/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:09:03 by chduong           #+#    #+#             */
/*   Updated: 2021/11/15 18:50:56 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static void	rotate(t_list **first)
{
	t_list	*second;

	if (!first || !*first)
		return ;
	second = (*first)->next;
	(ft_lstlast(*first))->next = *first;
	(*first)->next = NULL;
	*first = second;
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
