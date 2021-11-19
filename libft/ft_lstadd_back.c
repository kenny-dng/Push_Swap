/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:03:04 by chduong           #+#    #+#             */
/*   Updated: 2021/11/15 18:16:18 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **first, t_list *new)
{
	if (!first)
		return ;
	if (!*first)
		*first = new;
	else
		(ft_lstlast(*first))->next = new;
}
