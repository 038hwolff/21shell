/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/24 00:11:33 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		has_quotes_or_backslash(char *s)
{
	while (*s)
	{
		if (*s == '\'' || *s == '"' || *s == '\\')
			return (1);
		s++;
	}
	return (0);
}

void	remove_enclosing_chars(char **line, int begin, int end)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strnew(ft_strlen(*line) - 2);
	ft_strncpy(*line, tmp, begin);
	ft_strncpy(*line + begin, tmp + begin + 1, end - begin - 1);
	ft_strcpy(*line + end - 1, tmp + end + 1);
	ft_strdel(&tmp);
}

int		expand_dquote(char **line, int cur)
{
	int		begin;

	begin = cur++;
	while ((*line)[cur] && (*line)[cur] != '"')
	{
		if ((*line)[cur] == '\\'
			&& ((*line)[cur + 1] == '$' || (*line)[cur + 1] == '`'
			|| (*line)[cur + 1] == '"' || (*line)[cur + 1] == '\\'
			|| (*line)[cur + 1] == '\n'))
			cur = pop_char(line, cur);
		++cur;
	}
	remove_enclosing_chars(line, begin, cur);
	return (cur - 1);
}

int		expand_quote(char **line, int cur)
{
	int		begin;

	begin = cur++;
	while ((*line)[cur] && (*line)[cur] != '\'')
		++cur;
	remove_enclosing_chars(line, begin, cur);
	return (cur - 1);
}

void	remove_quotes_and_backslash(char **line)
{
	int		i;

	if (!*line)
		return ;
	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\\' && (*line)[i + 1])
			i = pop_char(line, i) + 1;
		else if ((*line)[i] == '\'')
			i = expand_quote(line, i);
		else if ((*line)[i] == '"')
			i = expand_dquote(line, i);
		else
			++i;
	}
}
