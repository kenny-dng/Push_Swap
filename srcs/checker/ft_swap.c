/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:08:48 by chduong           #+#    #+#             */
/*   Updated: 2021/12/02 18:00:28 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h" 

static void	swap(t_list **first)
{
	t_list	tmp;
	t_list	*second;

	if (!first || !*first)
		return ;
	tmp.val = (*first)->val;
	tmp.i = (*first)->i;
	second = (*first)->next;
	(*first)->val = second->val;
	(*first)->i = second->i;
	second->val = tmp.val;
	second->i = tmp.i;
}

void	swap_a(t_list **a)
{
	swap(a);
}

void	swap_b(t_list **b)
{
	swap(b);
}

void	swap_2(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}
