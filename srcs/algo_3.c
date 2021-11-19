/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2n3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:04:34 by chduong           #+#    #+#             */
/*   Updated: 2021/11/15 18:40:34 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **a)
{
	t_list	*a1;
	t_list	*a2;

	a1 = *a;
	a2 = a1->next;
	if (a1->val > a2->val)
		swap_a(a);
}

void	rev_sort_2(t_list **a)
{
	t_list	*a1;
	t_list	*a2;

	a1 = *a;
	a2 = a1->next;
	if (a1->val < a2->val)
		swap_a(a);
}

void	sort_3(t_list **a)
{
	t_list	*a1;
	t_list	*a2;
	t_list	*a3;

	while (not_sorted(*a))
	{
		a1 = *a;
		a2 = a1->next;
		a3 = a2->next;
		if (a1->val < a2->val && a2->val > a3->val && a1->val > a3->val)
			rrotate_a(a);
		else if (a1->val > a2->val && a2->val < a3->val && a1->val > a3->val)
			rotate_a(a);
		else
			swap_a(a);
	}
}

void	rev_sort_3(t_list **a)
{
	t_list	*a1;
	t_list	*a2;
	t_list	*a3;

	while (not_revsorted(*a))
	{
		a1 = *a;
		a2 = a1->next;
		a3 = a2->next;
		if (a1->val < a2->val && a2->val > a3->val && a1->val < a3->val)
			rotate_a(a);
		else if (a1->val > a2->val && a2->val < a3->val && a1->val < a3->val)
			rrotate_a(a);
		else
			swap_a(a);
	}
}
