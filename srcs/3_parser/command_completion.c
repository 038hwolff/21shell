/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_completion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/18 09:10:26 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_cancel(t_data *data, char **line)
{
	if (check_if_sigint(data, line))
		return (1);
	if (check_eof(data))
	{
		eof_exception();
		ft_strdel(line);
		return (1);
	}
	return (0);
}

void	complete_command_backslash(t_token *token, char **line)
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

void	complete_command_quote(t_token *token, char **line, char quotetype)
{
	int			len;
	char		*dupline;
	char		*dupline2;
	t_token		*nexttok;

	if (!token || !line || !*line)
		return ;
	len = 0;
	while ((*line)[len])
	{
		if ((*line)[len] == '\\' && quotetype == '"')
			++len && (*line)[len] && ++len;
		else if ((*line)[len] == quotetype)
		{
			++len;
			break ;
		}
		else
			++len;
	}
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

void	complete_tokens(t_token *token, int incomp_type, char **line)
{
	token = get_last_token(token);
	if (incomp_type == INC_QUOTE)
		complete_command_quote(token, line, '\'');
	else if (incomp_type == INC_DQUOTE)
		complete_command_quote(token, line, '"');
	else if (incomp_type == INC_BKSLASH)
		complete_command_backslash(token, line);
	del_tokens_if(&token, &token_is_newline);
	token = get_last_token(token);
	lexical_analysis(&token, *line);
}

int		is_command_incomplete(t_token *token)
{
	char	quotetype;

	if (!token)
		return (COMPLETE);
	if (!check_backslash(token))
		return (INC_BKSLASH);
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
