/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:17:05 by chduong           #+#    #+#             */
/*   Updated: 2021/12/03 15:03:41 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s1 == *s2 && --n)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

static void	fail_read(t_list **a, t_list **b, char **line)
{
	ft_putstr_fd("Error : \"", 1);
	ft_putstr_fd(*line, 1);
	ft_putstr_fd("\" is not an instruction to operation stack\n", 1);
	clear_all(a, b, line);
	exit(EXIT_FAILURE);
}

void	do_read(t_list **a, t_list **b, char **line)
{
	if (ft_strncmp(*line, "pa", 3) == 0)
		push_a(a, b);
	else if (ft_strncmp(*line, "pb", 3) == 0)
		push_b(a, b);
	else if (ft_strncmp(*line, "sa", 3) == 0)
		swap_a(a);
	else if (ft_strncmp(*line, "sb", 3) == 0)
		swap_b(b);
	else if (ft_strncmp(*line, "ss", 3) == 0)
		swap_2(a, b);
	else if (ft_strncmp(*line, "ra", 3) == 0)
		rotate_a(a);
	else if (ft_strncmp(*line, "rb", 3) == 0)
		rotate_b(b);
	else if (ft_strncmp(*line, "rr", 3) == 0)
		rotate_2(a, b);
	else if (ft_strncmp(*line, "rra", 4) == 0)
		rrotate_a(a);
	else if (ft_strncmp(*line, "rrb", 4) == 0)
		rrotate_b(b);
	else if (ft_strncmp(*line, "rrr", 4) == 0)
		rrotate_2(a, b);
	else
		fail_read(a, b, line);
}
