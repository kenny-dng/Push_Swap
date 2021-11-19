/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:00:56 by chduong           #+#    #+#             */
/*   Updated: 2021/11/18 15:01:21 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>

//	MACRO
# define P 1
# define S 2
# define R 3
# define RR 4

//	Structures

typedef struct s_sorted
{
	t_list	*from;
	t_list	*to;
	size_t	len;
}			t_sorted;

typedef struct s_move
{
	int		what;
	int		count;
	t_list	*stack;
}			t_move;

//	Utils
int				dist_i(t_list *n1, t_list *n2);
int				not_sorted(t_list *a);	// non trie croissant
int				not_revsorted(t_list *a);	// non trie decroissant
int				count_rot(t_list *stack, unsigned int min, unsigned int max);
int				count_rrot(t_list *last, unsigned int min, unsigned int max);

void			index_stack(t_list *stack, size_t n);
void			parse_arg(t_list **lst, int ac, char **av);
void			print_stack(t_list *a, t_list *b);

t_list			*initprev(t_list *lst);
unsigned int	find_mid(unsigned int max);

//	Stack Moves
void			push_a(t_list **a, t_list **b);
void			push_b(t_list **a, t_list **b);

void			rotate_a(t_list **a);
void			rotate_b(t_list **b);
void			rotate_2(t_list **a, t_list **b);

void			rrotate_a(t_list **a);
void			rrotate_b(t_list **b);
void			rrotate_2(t_list **a, t_list **b);

void			swap_a(t_list **a);
void			swap_b(t_list **b);
void			swap_2(t_list **a, t_list **b);

//	Sorting Algorithm
void			sort_2(t_list **a);
void			sort_3(t_list **a);
void			rev_sort_2(t_list **a);
void			rev_sort_3(t_list **a);
void			sort_6(t_list **a, t_list **b, unsigned int max);
void			big_sort(t_list **a);

#endif