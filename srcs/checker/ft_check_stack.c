/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:21:35 by chduong           #+#    #+#             */
/*   Updated: 2021/12/03 15:03:53 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_sorted(t_list *a)
{
	t_list	*first;

	first = a;
	while (a->next != first)
	{
		if (a->val > (a->next)->val)
			return (0);
		a = a->next;
	}
	return (1);
}

void	check_stack(t_list *a, t_list *b)
{
	if (is_sorted(a) && ft_lstsize(b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
