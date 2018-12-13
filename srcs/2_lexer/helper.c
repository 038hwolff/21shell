/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:11:43 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/11 16:39:12 by hben-yah         ###   ########.fr       */
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
			s = s + 2;
		if (*s == '"')
			break ;
		++s;
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
