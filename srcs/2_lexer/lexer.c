/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:42:02 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/28 20:39:56 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int
	crawl_word(char **line)
{
	char *begin;

	begin = *line;
	if (**line == '\\')
		++(*line);
	else if (**line == '"')
		*line = strdquote(*line + 1);
	else if (**line == '\'')
		*line = strquote(*line + 1);
	else if (**line == '`')
		*line = strbackquote(*line + 1);
	if (**line)
		++(*line);
	return (*line - begin);
}

t_token
	*get_next_token(char **line)
{
	t_token	*delim_token;
	t_token	*token;
	char	*begin;
	int		len;
	int		assign;

	begin = *line;
	len = 0;
	assign = 0;
	token = NULL;
	while (!(delim_token = get_delimitor_token(line))
		&& **line && !is_space_or_tab(**line))
	{
		**line == '=' && (assign = 1);
		len += crawl_word(line);
	}
	if (len)
		token = token_new(ft_strsub(begin, 0, len), len,
			(assign ? ASSIGNEMENT_WORD : WORD), delim_token);
	return (delim_token && !token ? delim_token : token);
}

void
	lexical_analysis(t_token **token, char *line)
{
	t_token *new;
	t_token *last;

	if (!line)
		return ;
	last = get_last_token(*token);
	while (*line)
	{
		discard_spaces_tabs(&line);
		if ((new = get_next_token(&line)))
		{
			if (!(*token))
			{
				*token = new;
				last = new;
			}
			else if (last)
			{
				last->next = new;
				last = new;
			}
			while (last->next)
				last = last->next;
		}
	}
}
