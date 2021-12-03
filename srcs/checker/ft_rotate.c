/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:09:03 by chduong           #+#    #+#             */
/*   Updated: 2021/12/02 18:00:24 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h" 

static void	rotate(t_list **first)
{
	if (!first || !*first)
		return ;
	*first = (*first)->next;
}

void	rotate_a(t_list **a)
{
	rotate(a);
}

void	rotate_b(t_list **b)
{
	rotate(b);
}

void	rotate_2(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
