/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:05:49 by chduong           #+#    #+#             */
/*   Updated: 2021/12/03 12:46:55 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*first;

	if (!lst || !*lst)
		return ;
	first = *lst;
	while ((*lst)->next != first)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
	ft_lstdelone(*lst);
	lst = NULL;
}
