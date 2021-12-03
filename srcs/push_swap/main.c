/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:40:53 by chduong           #+#    #+#             */
/*   Updated: 2021/12/02 12:56:56 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_list **a, t_list **b, t_uint max)
{
	make_third(a, b, max);
	divide_third(a, b);
	insertion_sort(a, b);
	go_top(a, max);
}

void	sort(t_list **a, t_list **b, t_uint len)
{
	if (len > 2)
		index_stack(*a, len);
	if (len == 2)
		sort_2(a);
	else if (len == 3)
		sort_3(a);
	else if (len > 3 && len <= 6)
		sort_6(a, b, len);
	else if (len > 6)
		big_sort(a, b, len);
	else
		return ;
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		parse_arg(&stack_a, ac, av);
		sort(&stack_a, &stack_b, ac - 1);
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
	}
	return (0);
}
