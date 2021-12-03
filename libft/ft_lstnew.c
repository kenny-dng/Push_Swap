/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:21:12 by chduong           #+#    #+#             */
/*   Updated: 2021/11/19 16:44:42 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int val)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	a->val = val;
	a->i = 0;
	a->prev = NULL;
	a->next = NULL;
	return (a);
}
