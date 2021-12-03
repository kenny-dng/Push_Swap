/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:09:49 by chduong           #+#    #+#             */
/*   Updated: 2021/11/12 17:04:39 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_tab(t_list *stack, size_t n)
{
	size_t	i;
	int		*tab;
	t_list	*top;

	i = 0;
	tab = malloc(sizeof(int) * n);
	top = stack;
	while (i < n)
	{
		tab[i] = stack->val;
		stack = stack->next;
		++i;
	}
	return (tab);
}

static void	sort_tab(int *tab, size_t n)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			++j;
		}
		++i;
	}
}

void	index_stack(t_list *stack, size_t n)
{
	int		*tab;
	size_t	i;
	t_list	*top;

	tab = stack_to_tab(stack, n);
	top = stack;
	sort_tab(tab, n);
	while (stack)
	{
		i = 0;
		while (i < n)
		{
			if (stack->val == tab[i])
			{
				stack->i = i;
				break ;
			}
			++i;
		}
		stack = stack->next;
		if (stack == top)
			stack = NULL;
	}
	free(tab);
}
