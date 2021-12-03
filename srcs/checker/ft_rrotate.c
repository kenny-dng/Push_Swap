/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:09:03 by chduong           #+#    #+#             */
/*   Updated: 2021/12/02 18:00:26 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rrotate(t_list **first)
{
	if (!first || !*first)
		return ;
	*first = (*first)->prev;
}

void	rrotate_a(t_list **a)
{
	rrotate(a);
}

void	rrotate_b(t_list **b)
{
	rrotate(b);
}

void	rrotate_2(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
}
