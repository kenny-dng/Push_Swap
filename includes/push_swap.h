/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:00:56 by chduong           #+#    #+#             */
/*   Updated: 2021/12/06 17:13:32 by chduong          ###   ########.fr       */
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

//	MACRO
# define P 1
# define S 2
# define R 3
# define RR 4

//	Type Definition
typedef int				t_bool;
typedef unsigned int	t_uint;

typedef struct s_move
{
	int		what;
	int		count;
}			t_move;

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

//	Others functions & Utils
int			dist_i(t_list *n1, t_list *n2);
int			is_following(t_list *a);

void		index_stack(t_list *stack, size_t n);
void		parse_arg(t_list **lst, int ac, char **av);
void		print_stack(t_list *a, t_list *b);

t_uint		i_min(t_list *stack);
t_uint		i_max(t_list *stack);

t_bool		not_sorted(t_list *a);
t_bool		not_revsorted(t_list *a);

//	Do next Moves
t_move		make_move(int what, int count);
void		do_move_a(t_move *ma, t_list **a, t_list **b);
void		do_move_b(t_move *mb, t_list **a, t_list **b);
void		double_move(t_move *ma, t_move *mb, t_list **a, t_list **b);

//	Little Algorithms
void		sort_2(t_list **a);
void		sort_3(t_list **a);
void		rev_sort_2(t_list **a);
void		rev_sort_3(t_list **a);
void		sort_6(t_list **a, t_list **b, t_uint max);

//	Functions of Main Algorithm
t_list		*best_push_b(t_list *a, t_list *b);
t_uint		count_rot_a(t_list *a, t_list *b_topush);

void		make_third(t_list **a, t_list **b, t_uint max);
void		divide_third(t_list **a, t_list **b);
void		insertion_sort(t_list **a, t_list **b);
void		go_top(t_list **a, t_uint max);

#endif