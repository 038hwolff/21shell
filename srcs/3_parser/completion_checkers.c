/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_checkers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/24 00:11:13 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int
	check_backslash(t_token *token)
{
	while (token->next)
		token = token->next;
	return (token->type == NEWLINE);
}

static char
	check_str_quote(char *s)
{
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
			else if (*s == '`')
				return ('`');
		}
		else if (*s == '`')
		{
			if (!*(s = strbackquote(s + 1)))
				return ('`');
		}
		*s && ++s;
	}
	return (0);
}

char
	check_quote(t_token *token)
{
	while (token->next && token->next->type != NEWLINE)
		token = token->next;
	return (check_str_quote(token->val));
}

int
	check_control_op(t_token *token, int type)
{
	while (token)
	{
		if (token->type == type
			&& !get_next_relevant_token(token))
			return (0);
		token = token->next;
	}
	return (1);
}

int
	check_parentheses(t_token *token)
{
	while (token)
	{
		if (token->type == OPEN_PAR)
		{
			while (token && token->type != CLOSED_PAR)
				token = token->next;
			if (!token)
				return (0);
		}
		token = token->next;
	}
	return (1);
}
