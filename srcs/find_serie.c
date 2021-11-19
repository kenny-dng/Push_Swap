/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_serie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:49:45 by chduong           #+#    #+#             */
/*   Updated: 2021/11/19 16:37:18 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_sorted	make_serie(t_list *from, t_list *to, size_t len)
{
	t_sorted	s;

	s.from = from;
	s.to = to;
	s.len = len;
	return (s);
}

static t_sorted	find_serie(t_list *a)
{
	size_t	len;
	t_list	*tmp;

	len = 1;
	while (a->next)
	{
		tmp = a;
		while (tmp->next && tmp->i < (tmp->next)->i)
		{
			len += 1;
			tmp = tmp->next;
		}
		if (len > 1)
			break ;
		a = a->next;
	}
	if (len > 1)
		return (make_serie(a, tmp, len));
	else
		return (make_serie(NULL, NULL, 0));
}

t_sorted	biggest_serie(t_list *a)
{
	t_sorted	s1;
	t_sorted	s2;

	s1 = find_serie(a);
	a = (s1.to)->next;
	while (a)
	{
		s2 = find_serie(a);
		if ((s1.len < s2.len)
			|| (s1.len == s2.len && (s1.to)->i < (s2.to)->i))
			s1 = s2;
		a = s2.to;
	}
	return (s1);
}

void	big_sort(t_list **a)
{
	t_sorted	s;

	s = biggest_serie(*a);
	printf("[%ld ; %ld] : %ld\n", (s.from)->val, (s.to)->val, s.len);	
}
