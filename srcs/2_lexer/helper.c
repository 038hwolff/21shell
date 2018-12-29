/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:11:43 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/29 17:55:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_space_or_tab(char c)
{
	return (c == ' ' || c == '\t');
}

void	discard_spaces_tabs(char **line)
{
	while (is_space_or_tab(**line))
		++(*line);
}

char	*strdquote(char *s)
{
	while (*s)
	{
		if (*s == '\\')
			++s;
		else if (*s == '"')
			break ;
		else if (*s == '`')
			s = strbackquote(s + 1);
		*s && ++s;
	}
	return (s);
}

char	*strquote(char *s)
{
	while (*s)
	{
		if (*s == '\'')
			break ;
		++s;
	}
	return (s);
}

char	*strbackquote(char *s)
{
	while (*s)
	{
		if (*s == '\\')
			++s;
		else if (*s == '`')
			break ;
		*s && ++s;
	}
	return (s);
}
