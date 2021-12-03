/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:56:00 by chduong           #+#    #+#             */
/*   Updated: 2021/11/24 19:16:57 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_stack(t_list **a, t_list **b, t_uint mid)
{
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->i < mid)
			push_b(a, b);
		else
		{
			if (((*a)->next)->i < mid || (((*a)->next)->next)->i < mid)
				rotate_a(a);
			else
				rrotate_a(a);
		}
	}
	sort_3(a);
	if (ft_lstsize(*b) == 3)
		rev_sort_3(b);
	else if (ft_lstsize(*b) == 2)
		rev_sort_2(b);
}

static t_uint	find_mid(t_uint max)
{
	if (max < 4)
		return (0);
	else if (max == 4)
		return (1);
	else if (max == 5)
		return (2);
	else
		return (max / 2);
}

void	sort_6(t_list **a, t_list **b, t_uint max)
{
	int	n;

	if (!not_sorted(*a))
		return ;
	divide_stack(a, b, find_mid(max));
	n = ft_lstsize(*b);
	while (n--)
		push_a(a, b);
}
