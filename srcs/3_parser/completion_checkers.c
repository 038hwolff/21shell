/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_checkers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 22:25:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_backslash(t_token *token)
{
	while (token->next && token->next->type != NEWLINE)
		token = token->next;
	if (token->type == NEWLINE)
		return (1);
	if (token->val[token->length - 2] == '\\')
		return (0);
	return (1);
}

char	check_quote(t_token *token)
{
	char	*s;

	while (token->next && token->next->type != NEWLINE)
		token = token->next;
	s = token->val;
	while (*s)
	{
		if (*s == '\\')
			++s;
		else if (*s == '\'')
		{
			if (!*(s = strquote(s + 1)))
				return ('\'');
		}
		else if (*s == '"')
		{
			if (!*(s = strdquote(s + 1)))
				return ('"');
		}
		*s && ++s;
	}
	return (0);
}

int		check_pipe(t_token *token)
{
	while (token)
	{
		if (token->type == PIPE
			&& !get_next_relevant_token(token))
			return (0);
		token = token->next;
	}
	return (1);
}

int		check_or(t_token *token)
{
	while (token)
	{
		if (token->type == DOUBLEPIPE
			&& !get_next_relevant_token(token))
			return (0);
		token = token->next;
	}
	return (1);
}

int		check_and(t_token *token)
{
	while (token)
	{
		if (token->type == DOUBLEAND
			&& !get_next_relevant_token(token))
			return (0);
		token = token->next;
	}
	return (1);
}
