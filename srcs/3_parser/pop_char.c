/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:59:04 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/11 13:25:05 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		pop_char(char **line, int i)
{
	char	*tmp;

	tmp = *line;
	try_m((*line = ft_strnew(ft_strlen(*line) - 1)));
	ft_strncpy(*line, tmp, i);
	ft_strcpy(*line + i, tmp + (i + 1));
	ft_strdel(&tmp);
	return (i);
}

int		pop_backslashed_nl(char **line)
{
	char	*tmp;
	size_t	len;

	if (line && *line && (len = ft_strlen(*line)) && len > 1)
	{
		len -= 2;
		try_m((tmp = ft_strsub(*line, 0, len)));
		ft_strdel(line);
		*line = tmp;
		return (len);
	}
	return (-1);
}

void	pop_backslash_in_heredoc(char **s)
{
	int		i;

	if (!s || !*s)
		return ;
	i = 0;
	while ((*s)[i])
	{
		if ((*s)[i] == '\\'
			&& ((*s)[i + 1] == '\\' || (*s)[i + 1] == '\n'
			|| (*s)[i + 1] == '`' || (*s)[i + 1] == '$'))
			i = pop_char(s, i);
		else
			++i;
	}
}
