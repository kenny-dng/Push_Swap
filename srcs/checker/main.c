/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:13:16 by chduong           #+#    #+#             */
/*   Updated: 2021/12/03 13:24:09 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	clear_all(t_list **a, t_list **b, char **line)
{
	free(*line);
	*line = NULL;
	ft_lstclear(a);
	ft_lstclear(b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*line;

	a = NULL;
	b = NULL;
	line = NULL;
	if (ac > 1)
		parse_arg(&a, ac, av);
	while (get_next_line(0, &line))
		do_read(&a, &b, &line);
	check_stack(a, b);
	clear_all(&a, &b, &line);
	return (0);
}
