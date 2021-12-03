/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:11:46 by chduong           #+#    #+#             */
/*   Updated: 2021/12/02 18:28:00 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*save_join(char *save, char *buff);
int		get_next_line(int fd, char **line);

#endif