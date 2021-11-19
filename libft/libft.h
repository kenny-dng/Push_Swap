/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennyduong <kennyduong@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:09:34 by chduong           #+#    #+#             */
/*   Updated: 2021/11/17 17:07:32 by kennyduong       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	long int		val;
	unsigned int	i;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

long int	ft_atol(const char *str);
size_t		ft_strlen(const char *s);
size_t		ft_ilen(long int nb);

int			ft_isdigit(int c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

void		ft_lstadd_front(t_list **first, t_list *new);
void		ft_lstadd_back(t_list **first, t_list *new);
void		ft_lstdelone(t_list *lst);
void		ft_lstclear(t_list **lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));
size_t		ft_lstsize(t_list *lst);

t_list		*ft_lstnew(int val);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
