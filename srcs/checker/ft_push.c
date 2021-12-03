/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:08:39 by chduong           #+#    #+#             */
/*   Updated: 2021/12/02 18:00:23 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	}
}
