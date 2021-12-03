/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:14:20 by chduong           #+#    #+#             */
/*   Updated: 2021/12/03 17:18:11 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	invalid_str(const char *str)
{
	int	i;

	i = 0;
	if (*str == '+' || *str == '-')
		++str;
	if (*str == 0)
		return (1);
	while (str[i])
	{
		if (!(ft_isdigit(str[i])) || i > 10)
			return (1);
		++i;
	}
	return (0);
}

static int	invalid_nb(t_list *lst, long int nb)
{
	t_list	*first;

	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	first = lst;
	while (lst)
	{
		if (nb == lst->val)
			return (1);
		if (lst->next != first)
			lst = lst->next;
		else
			break ;
	}
	return (0);
}

void	parse_arg(t_list **lst, int ac, char **av)
{
	int			i;
	long int	nb;

	i = 1;
	while (i < ac)
	{
		if (invalid_str(av[i]))
		{
			ft_putstr_fd("Error\n", 1);
			ft_lstclear(lst);
			exit(EXIT_FAILURE);
		}
		nb = ft_atol(av[i++]);
		if (invalid_nb(*lst, nb))
		{
			ft_putstr_fd("Error\n", 1);
			ft_lstclear(lst);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(lst, ft_lstnew(nb));
	}
}
