/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:59:42 by kennyduong        #+#    #+#             */
/*   Updated: 2021/11/19 15:12:20 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->val > (a->next)->val || dist_i(a, a->next) > 1)
			return (1);
		a = a->next;
	}
	return (0);
}

int	not_revsorted(t_list *a)
{
	while (a->next)
	{
		if (a->val < (a->next)->val || dist_i(a, a->next) > 1)
			return (1);
		a = a->next;
	}
	return (0);
}
