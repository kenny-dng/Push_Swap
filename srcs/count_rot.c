/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:11:10 by chduong           #+#    #+#             */
/*   Updated: 2021/11/19 14:28:55 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rot(t_list *stack, unsigned int min, unsigned int max)
{
	int	r;

	r = 0;
	while (stack->next)
	{
		if (stack->i >= min && stack->i <= max)
			return (r);
		++r;
		stack = stack->next;
	}
	return (-1);
}

int	count_rrot(t_list *last, unsigned int min, unsigned int max)
{
	int	rr;

	rr = 1;
	while (last->prev)
	{
		if (last->i >= min && last->i <= max)
			return (rr);
		++rr;
		last = last->prev;
	}
	return (-1);
}

t_list	*initprev(t_list *lst)
{
	if (!lst)
		return (NULL);
	lst->prev = NULL;
	while (lst->next)
	{
		(lst->next)->prev = lst;
		lst = lst->next;
	}
	return (lst);
}
