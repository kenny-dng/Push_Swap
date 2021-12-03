/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_step1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:51:22 by chduong           #+#    #+#             */
/*   Updated: 2021/11/30 18:07:33 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_uint	mediane(t_list *stack)
{
	t_uint	min;
	t_uint	max;
	t_list	*first;

	min = stack->i;
	max = stack->i;
	first = stack;
	while (stack->next != first)
	{
		stack = stack->next;
		if (min > stack->i)
			min = stack->i;
		if (max < stack->i)
			max = stack->i;
	}
	return (((max - min) / 2) + min);
}

static t_move	next_move_a(t_list *a, t_uint max)
{
	if (a->i > max * 2 / 3)
		return (make_move(R, 1));
	else
		return (make_move(P, 1));
}

static t_move	next_move_b(t_list **b, t_uint size_b)
{
	if (size_b == 3)
		rev_sort_3(b);
	if (size_b > 3 && (*b)->i <= mediane(*b))
		return (make_move(R, 1));
	else
		return (make_move(0, 0));
}

void	make_third(t_list **a, t_list **b, t_uint max)
{
	t_move	ma1;
	t_move	ma2;
	t_move	mb;

	while (ft_lstsize(*a) > max / 3)
	{
		ma1 = next_move_a(*a, max);
		ma2 = next_move_a((*a)->next, max);
		if (ma1.what == P)
		{
			do_move_a(&ma1, a, b);
			mb = next_move_b(b, ft_lstsize(*b));
			if (ma2.what == P)
				do_move_b(&mb, a, b);
		}
		else
			double_move(&ma1, &mb, a, b);
	}
	do_move_b(&mb, a, b);
}

void	divide_third(t_list **a, t_list **b)
{
	t_uint	size_a;
	t_uint	mid;

	size_a = ft_lstsize(*a);
	while (size_a > 3)
	{
		mid = size_a / 2;
		while (size_a > mid && size_a > 3)
		{
			if ((*a)->i <= mediane(*a))
			{
				push_b(a, b);
				--size_a;
			}
			else
				rotate_a(a);
		}
	}
	sort_3(a);
}
