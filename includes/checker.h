/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:40:16 by chduong           #+#    #+#             */
/*   Updated: 2021/12/03 15:04:20 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "gnl.h"

void		parse_arg(t_list **lst, int ac, char **av);
void		check_stack(t_list *a, t_list *b);
void		do_read(t_list **a, t_list **b, char **line);
void		clear_all(t_list **a, t_list **b, char **line);

//	Stack Operations
void		push_a(t_list **a, t_list **b);
void		push_b(t_list **a, t_list **b);

void		rotate_a(t_list **a);
void		rotate_b(t_list **b);
void		rotate_2(t_list **a, t_list **b);

void		rrotate_a(t_list **a);
void		rrotate_b(t_list **b);
void		rrotate_2(t_list **a, t_list **b);

void		swap_a(t_list **a);
void		swap_b(t_list **b);
void		swap_2(t_list **a, t_list **b);

#endif