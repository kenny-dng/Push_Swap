/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:11:10 by chduong           #+#    #+#             */
/*   Updated: 2021/12/02 18:26:39 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*save_join(char *save, char *buff)
{
	char	*newsave;
	int		i;

	i = 0;
	if (!save && !buff)
		return (NULL);
	newsave = malloc(sizeof(char *) * (ft_strlen(save) + ft_strlen(buff) + 1));
	if (!newsave)
		return (NULL);
	while (save && save[i])
	{	
		newsave[i] = save[i];
		++i;
	}
	while (*buff)
	{
		newsave[i++] = *buff;
		++buff;
	}
	newsave[i] = 0;
	if (save)
		free(save);
	return (newsave);
}
