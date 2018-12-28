/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_completion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/28 17:51:14 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		complete_command_backslash(t_token *token, char **line)
{
	char		*dupline;
	char		*dupline2;
	t_token		*nexttok;

	if (!token || !line || !*line)
		return ;
	token->length = pop_backslashed_nl(&token->val);
	try_m((dupline = ft_strdup(*line)));
	dupline2 = dupline;
	nexttok = get_next_token(&dupline);
	if (nexttok && nexttok->type == WORD)
	{
		merge_tokens(token, nexttok);
		ft_strdel(line);
		try_m(*line = ft_strdup(dupline));
		ft_strdel(&dupline2);
	}
}

static int	get_next_word_len(char *line, char quotetype)
{
	int			len;

	len = 0;
	while (line[len])
	{
		if (line[len] == '\\' && quotetype == '"')
			++len && line[len] && ++len;
		else if (line[len] == quotetype)
		{
			++len;
			break ;
		}
		else
			++len;
	}
	return (len);
}

void		complete_command_quote(t_token *token, char **line, char quotetype)
{
	int			len;
	char		*dupline;
	char		*dupline2;
	t_token		*nexttok;

	if (!token || !line || !*line)
		return ;
	len = get_next_word_len(*line, quotetype);
	append_token_value(token, len, line);
	try_m((dupline = ft_strdup(*line)));
	dupline2 = dupline;
	nexttok = get_next_token(&dupline);
	if (nexttok && nexttok->type == WORD)
	{
		merge_tokens(token, nexttok);
		ft_strdel(line);
		try_m(*line = ft_strdup(dupline));
		ft_strdel(&dupline2);
	}
}

void		complete_tokens(t_token *token, int incomp_type, char **line)
{
	del_tokens_if(&token, &token_is_newline);
	token = get_last_token(token);
	if (incomp_type == INC_QUOTE)
		complete_command_quote(token, line, '\'');
	else if (incomp_type == INC_DQUOTE)
		complete_command_quote(token, line, '"');
	else if (incomp_type == INC_BKSLASH)
		complete_command_backslash(token, line);
	get_data()->dev && print_lex(get_data()->token, "PARSER INCOMPLETE");
	token = get_last_token(token);
	lexical_analysis(&token, *line);
}

int			is_command_incomplete(t_token *token)
{
	char	quotetype;

	if (!token)
		return (COMPLETE);
	if (!check_backslash(token))
		return (INC_BKSLASH);
	if (!check_parentheses(token))
		return (INC_PARENT);
	quotetype = check_quote(token);
	if (quotetype == '"')
		return (INC_DQUOTE);
	if (quotetype == '\'')
		return (INC_QUOTE);
	if (!check_pipe(token))
		return (INC_PIPE);
	if (!check_or(token))
		return (INC_DPIPE);
	if (!check_and(token))
		return (INC_DAND);
	return (COMPLETE);
}
