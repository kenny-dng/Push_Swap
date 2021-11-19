/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_step1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:51:22 by chduong           #+#    #+#             */
/*   Updated: 2021/11/19 14:19:18 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_move	make_move(int what, int count, t_list *stack)
{
	t_move	move;

	move.what = what;
	move.count = count;
	move.stack = stack;
}

t_move	next_move_a(t_list *a, unsigned int min, unsigned int max)
{
	int	r;
	int	rr;

	if (a->i >= min && a->i <= max)
		return (make_move(P, 1, a));
	else if ((a->i > (a->next)->i 
		&& !((a->next)->i >= min && (a->next)->i <= max))
		return (make_move(S, 1, a));
	else
	{
		r = count_rot(a, min, max);
		rr = count_rrot(initprev(a), min, max);
	}
	if (r < rr)
		return (make_move(R, r, a));
	else if (r > rr)
		return (make_move(RR, rr, a));
	else if (r == rr && r > 0)
		return (make_move(R, r, a));
	else
		return (make_move(0, 0, NULL));
}

t_move  sort_b()
{
    
}
