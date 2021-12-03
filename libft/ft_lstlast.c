/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:59:11 by chduong           #+#    #+#             */
/*   Updated: 2021/11/19 18:32:11 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*first;

	if (!lst)
		return (NULL);
	first = lst;
	while (lst->next != first)
		lst = lst->next;
	return (lst);
}
