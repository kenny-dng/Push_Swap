/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:03:04 by chduong           #+#    #+#             */
/*   Updated: 2021/11/19 18:30:13 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **first, t_list *new)
{
	t_list	*last;

	if (!first)
		return ;
	if (!*first)
	{
		new->next = new;
		new->prev = new;
		*first = new;
	}
	else
	{
		last = ft_lstlast(*first);
		last->next = new;
		new->prev = last;
		new->next = *first;
		(*first)->prev = new;
	}
}
