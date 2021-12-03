/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:21:35 by chduong           #+#    #+#             */
/*   Updated: 2021/11/25 17:03:02 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	not_sorted(t_list *a)
{
	t_list	*first;

	first = a;
	while (a->next != first)
	{
		if (is_following(a) < 0)
			return (1);
		a = a->next;
	}
	return (0);
}

t_bool	not_revsorted(t_list *b)
{
	t_list	*first;

	first = b;
	while (b->next != first)
	{
		if (is_following(b) > 0)
			return (1);
		b = b->next;
	}
	return (0);
}
