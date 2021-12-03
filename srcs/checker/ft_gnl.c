/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chduong <chduong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:07:09 by chduong           #+#    #+#             */
/*   Updated: 2021/12/03 13:42:49 by chduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static int	newline(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

static int	stock_buff(int fd, char **save)
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = 0;
		*save = save_join(*save, buff);
		if (newline(buff) > -1)
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (ret > 0)
		return (1);
	return (ret);
}

static void	save_rest(char *s)
{
	int	i;
	int	j;

	i = newline(s);
	j = 0;
	if (i >= 0)
	{
		++i;
		while (s[i])
			s[j++] = s[i++];
		s[j] = 0;
	}
}

static char	*get_line(char *s)
{
	char	*line;
	int		len;
	size_t	i;

	i = 0;
	len = newline(s);
	if (len < 0)
		len = ft_strlen(s);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	if (s)
	{
		while (s[i])
		{
			if (s[i] == '\n' || s[i] == 0)
				break ;
			line[i] = s[i];
			++i;
		}	
		save_rest(s);
	}
	line[i] = '\0';
	return (line);
}

int	get_next_line(int fd, char **line)
{
	int			output;
	static char	*save;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	output = 1;
	if (!save || newline(save) < 0)
		output = stock_buff(fd, &save);
	if (output > -1)
	{
		free(*line);
		*line = get_line(save);
	}
	if (output < 1 && save)
		free(save);
	if (!*line)
		return (-1);
	return (output);
}
