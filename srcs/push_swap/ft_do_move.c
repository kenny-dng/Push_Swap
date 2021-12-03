/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:58:19 by chduong           #+#    #+#             */
/*   Updated: 2021/11/30 17:23:09 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	make_move(int what, int count)
{
	t_move	move;

	move.what = what;
	move.count = count;
	return (move);
}

void	do_move_a(t_move *ma, t_list **a, t_list **b)
{
	if (ma->count > 0)
	{
		if (ma->what == P)
			push_b(a, b);
		else if (ma->what == S)
			swap_a(a);
		else if (ma->what == R)
			rotate_a(a);
		else if (ma->what == RR)
			rrotate_a(a);
		ma->count -= 1;
	}
}

void	do_move_b(t_move *mb, t_list **a, t_list **b)
{
	if (mb->count > 0)
	{
		if (mb->what == P)
			push_a(a, b);
		else if (mb->what == S)
			swap_b(b);
		else if (mb->what == R)
			rotate_b(b);
		else if (mb->what == RR)
			rrotate_b(b);
		mb->count -= 1;
	}
}

void	double_move(t_move *ma, t_move *mb, t_list **a, t_list **b)
{
	if (ma->count && mb->count && ma->what == mb->what)
	{
		if (ma->what == S)
			swap_2(a, b);
		else if (ma->what == R)
			rotate_2(a, b);
		else if (ma->what == RR)
			rrotate_2(a, b);
		ma->count -= 1;
		mb->count -= 1;
	}
	else
	{
		do_move_a(ma, a, b);
		do_move_b(mb, a, b);
	}
}
