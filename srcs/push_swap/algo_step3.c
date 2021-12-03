/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_step3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:18:02 by chduong           #+#    #+#             */
/*   Updated: 2021/11/30 18:38:16 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_move	next_ma(t_list *a, t_list *b)
{
	t_uint	r;
	t_uint	rr;

	r = count_rot_a(a, b);
	rr = ft_lstsize(a) - r;
	if (r <= rr)
		return (make_move(R, r));
	else if (r > rr)
		return (make_move(RR, rr));
	else
		return (make_move(0, 0));
}

static t_move	next_mb(t_list *b, t_list *to_push)
{
	t_uint	r;
	t_uint	rr;

	r = 0;
	while (b != to_push)
	{
		b = b->next;
		++r;
	}
	rr = ft_lstsize(b) - r;
	if (r == 0)
		return (make_move(P, 1));
	else if (r <= rr)
		return (make_move(R, r));
	else if (r > rr)
		return (make_move(RR, rr));
	else
		return (make_move(0, 0));
}

void	insertion_sort(t_list **a, t_list **b)
{
	t_list	*bpb;
	t_move	ma;
	t_move	mb;

	while (ft_lstsize(*b) > 0)
	{
		bpb = best_push_b(*a, *b);
		ma = next_ma(*a, bpb);
		mb = next_mb(*b, bpb);
		while (ma.count || mb.what != P)
		{
			if (mb.what != P)
				double_move(&ma, &mb, a, b);
			else
				do_move_a(&ma, a, b);
			if (mb.count == 0)
				mb = next_mb(*b, bpb);
		}
		do_move_b(&mb, a, b);
	}
}

void	go_top(t_list **a, t_uint max)
{
	t_uint	r;
	t_uint	rr;
	t_list	*tmp;

	tmp = *a;
	r = 0;
	while (tmp->next != *a)
	{
		if (tmp->i == 0)
			break ;
		tmp = tmp->next;
		++r;
	}
	rr = max - r;
	if (r <= rr)
	{	
		while (r--)
			rotate_a(a);
	}
	else
	{
		while (rr--)
			rrotate_a(a);
	}
}
