/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:08:39 by chduong           #+#    #+#             */
/*   Updated: 2021/11/19 18:12:51 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cut_stack(t_list *stack)
{
	stack->prev = NULL;
	stack->next = NULL;
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*move;
	t_list	*last;

	if (*b)
	{
		move = *b;
		if ((*b)->next != move)
		{
			last = ft_lstlast(*b);
			*b = (*b)->next;
			last->next = *b;
			(*b)->prev = last;
		}
		else
			*b = NULL;
		cut_stack(move);
		ft_lstadd_front(a, move);
		ft_putstr_fd("pa\n", 1);
	}
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*move;
	t_list	*last;

	if (*a)
	{
		move = *a;
		if ((*a)->next != move)
		{
			last = ft_lstlast(*a);
			*a = (*a)->next;
			last->next = *a;
			(*a)->prev = last;
		}
		else
			*b = NULL;
		cut_stack(move);
		ft_lstadd_front(b, move);
		ft_putstr_fd("pb\n", 1);
	}
}
