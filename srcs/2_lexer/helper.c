/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:11:43 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/23 21:10:08 by hben-yah         ###   ########.fr       */
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
	char *c;

	while (*s)
	{
		if (*s == '\\')
			++s;
		else if (*s == '"')
			break ;
		else if (*s == '`')
		{
			if (!*(c = strbackquote(s + 1)))
				return (s);
			else
				s = c;
		}
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
