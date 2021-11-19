/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:37:31 by chduong           #+#    #+#             */
/*   Updated: 2021/11/18 16:51:11 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_case(t_list *stack)
{
	size_t	i;

	i = 0;
	if (stack)
	{
		while (i < (11 - ft_ilen(stack->val)))
		{
			ft_putchar_fd(' ', 1);
			++i;
		}
		ft_putnbr_fd(stack->val, 1);
	}
	else
		ft_putstr_fd("           ", 1);
}

static void	print_line(t_list *a, t_list *b)
{
	ft_putstr_fd("| ", 1);
	print_case(a);
	ft_putstr_fd(" || ", 1);
	print_case(b);
	ft_putstr_fd(" |\n", 1);
}

void	print_stack(t_list *a, t_list *b)
{
	ft_putstr_fd("\n|-------------||-------------|\n", 1);
	ft_putstr_fd("|      A      ||      B      |\n", 1);
	ft_putstr_fd("|=============||=============|\n", 1);
	while (a || b)
	{
		print_line(a, b);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_putstr_fd("|=============||=============|\n", 1);
	ft_putstr_fd("|      A      ||      B      |\n", 1);
	ft_putstr_fd("|-------------||-------------|\n\n", 1);
}
