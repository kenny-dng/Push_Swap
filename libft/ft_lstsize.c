/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:14:06 by chduong           #+#    #+#             */
/*   Updated: 2021/11/19 18:32:16 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*first;

	if (!lst)
		return (0);
	i = 1;
	first = lst;
	while (lst->next != first)
	{
		++i;
		lst = lst->next;
	}
	return (i);
}
