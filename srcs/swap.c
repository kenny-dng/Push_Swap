/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:08:48 by chduong           #+#    #+#             */
/*   Updated: 2021/11/15 18:40:45 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static void	swap(t_list **first)
{
	t_list	*second;

	if (!first || !*first)
		return ;
	second = (*first)->next;
	(*first)->next = second->next;
	second->next = *first;
	*first = second;
}

void	swap_a(t_list **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_list **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_2(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
