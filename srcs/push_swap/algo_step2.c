/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_step2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:02:17 by chduong           #+#    #+#             */
/*   Updated: 2021/11/30 16:14:36 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	is_goodplace(t_list *a, t_list *b)
{
	if ((a->prev)->i < b->i && b->i < a->i)
		return (1);
	else if ((a->prev)->i == i_max(a) && a->i == i_min(a))
	{
		if (b->i < a->i && b->i < (a->prev)->i)
			return (1);
		else if (b->i > a->i && b->i > (a->prev)->i)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

t_uint	count_rot_a(t_list *a, t_list *b_topush)
{
	t_list	*a1;
	t_uint	count;

	count = 0;
	a1 = a;
	if (is_goodplace(a, b_topush))
		return (count);
	while (a->next != a1)
	{
		a = a->next;
		++count;
		if (is_goodplace(a, b_topush))
			return (count);
	}
	return (0);
}

static t_uint	count_move(t_list *a, t_list *b_topush, t_uint rb)
{
	t_uint	ra;
	t_uint	rra;
	t_uint	rrb;

	ra = count_rot_a(a, b_topush);
	rra = ft_lstsize(a) - ra;
	rrb = ft_lstsize(b_topush) - rb;
	if (ra <= rra && rb <= rrb && ra >= rb)
		return (ra);
	else if (ra <= rra && rb <= rrb && ra < rb)
		return (rb);
	else if (ra > rra && rb > rrb && rra >= rrb)
		return (rra);
	else if (ra > rra && rb > rrb && rra < rrb)
		return (rrb);
	else if (ra <= rra && rb > rrb)
		return (ra + rrb);
	else
		return (rra + rb);
}

t_list	*best_push_b(t_list *a, t_list *b)
{
	t_list	*b1;
	t_list	*best;
	t_uint	rb;
	t_uint	move[2];

	b1 = b;
	rb = 0;
	best = b;
	move[0] = count_move(a, b, rb);
	while (b->next != b1)
	{
		b = b->next;
		move[1] = count_move(a, b, ++rb);
		if (move[0] > move[1])
		{
			move[0] = move[1];
			best = b;
		}
	}
	return (best);
}
