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

	i = 0;
	tab = malloc(sizeof(int) * n);
	while (i < n && stack)
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

	tab = stack_to_tab(stack, n);
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
	}
	free(tab);
}

int	dist_i(t_list *n1, t_list *n2)
{
	int	dist;

	if (!n1 || !n2)
		return (0);
	dist = n1->i - n2->i;
	if (dist < 0)
		dist = dist * -1;
	return (dist);
}
