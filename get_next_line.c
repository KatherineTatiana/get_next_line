/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 02:14:47 by ksoto             #+#    #+#             */
/*   Updated: 2019/11/04 21:05:38 by ksoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_line(char **str, char **line, int fd)
{
	char	*tmp;
	int		count;

	count = 0;
	while (str[fd][count] != '\0' && str[fd][count] != '\n')
		count++;
	*line = ft_strsub(str[fd], 0, count);
	if (str[fd][count] == '\n')
	{
		tmp = ft_strdup(&str[fd][count + 1]);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else
		ft_strdel(&str[fd]);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			reader;
	char		*tmp;
	char		buffer[BUFF_SIZE + 1];
	static char	*str[4864];

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	while ((reader = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (str[fd] == NULL && reader == 0)
		return (0);
	return (ft_read_line(str, line, fd));
}
