/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:59:42 by kennyduong        #+#    #+#             */
/*   Updated: 2021/11/26 04:57:49 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dist_i(t_list *n1, t_list *n2)
{
	int	dist;

	if (!n1 || !n2)
		return (0);
	dist = n1->i - n2->i;
	if (dist < 0)
		dist = dist * -1;
	return (dist);
}

t_uint	i_max(t_list *stack)
{
	t_uint	maxi;
	t_list	*first;

	maxi = stack->i;
	first = stack;
	while (stack->next != first)
	{
		if (maxi < stack->i)
			maxi = stack->i;
		stack = stack->next;
	}
	if (maxi < stack->i)
		maxi = stack->i;
	return (maxi);
}

t_uint	i_min(t_list *stack)
{
	t_uint	mini;
	t_list	*first;

	mini = stack->i;
	first = stack;
	while (stack->next != first)
	{
		if (mini > stack->i)
			mini = stack->i;
		stack = stack->next;
	}
	if (mini > stack->i)
		mini = stack->i;
	return (mini);
}

int	is_following(t_list *a)
{
	int	dist;

	dist = dist_i(a, a->next);
	if (a->i < (a->next)->i && dist == 1)
		return (1);
	else if (a->i < (a->next)->i && dist > 1)
		return (2);
	else if (a->i > (a->next)->i && dist == 1)
		return (-1);
	else if (a->i > (a->next)->i && dist > 1)
		return (-2);
	else
		return (0);
}
