/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:06:09 by hben-yah          #+#    #+#             */
/*   Updated: 2018/06/03 17:47:27 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

static int	merge(char **s1, char *s2)
{
	char *tmp;

	tmp = *s1;
	if (!(*s1 = ft_strjoin(*s1, s2)))
		return (0);
	ft_strdel(&tmp);
	return (1);
}

static int	slice(char **s1, char **s2)
{
	char	*tmp;
	int		index;
	size_t	len;

	if (((index = ft_indexof('\n', *s2)) > -1))
	{
		if (!(*s1 = ft_strsub(*s2, 0, index)))
			return (0);
	}
	else if (!(*s1 = ft_strdup(*s2)))
		return (0);
	tmp = *s2;
	len = ft_strlen(*s1) + (index > -1);
	if (!(*s2 = ft_strsub(*s2, len, ft_strlen(*s2) - len)))
		return (0);
	ft_strdel(&tmp);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*files[FD_MAX + 1];
	char		buff[BUFF_SIZE + 1];
	int			len;

	if (fd < 0 || fd > FD_MAX
		|| (!files[fd] && !(files[fd] = ft_strnew(1))) || !line)
		return (-1);
	len = 0;
	while (ft_indexof('\n', files[fd]) < 0
			&& (len = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[len] = '\0';
		if (!(merge(&files[fd], buff)))
			return (-1);
	}
	if (len < 0)
		return (-1);
	if (!*files[fd])
		return (0);
	if (!slice(line, &files[fd]))
		return (-1);
	return (**line || files[fd]);
}
