/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:40:53 by chduong           #+#    #+#             */
/*   Updated: 2021/11/18 15:17:48 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a, t_list **b, int len)
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
		big_sort(a);
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
		print_stack(stack_a, stack_b);
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
		// system("leaks out");
	}
	return (0);
}
