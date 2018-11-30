/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_incomplete_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/22 23:50:45 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** check_quote :
** Retourne la valeur ascii correspondant à la quote si cette dernière a été
** ouverte mais n'a pas été fermée, sinon retourne 0.
*/

char			check_quote(t_token *token)
{
	char	*s;

	s = get_last_token(token)->val;
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

/*
** check_pipe :
** Retourne -1 si un |, && ou || est trouvé en fin de ligne envoyée par
** l'utilisateur.
** Sinon retourne 0.
*/

int				check_pipe(t_token *token)
{
	while (token)
	{
		if (token->type == PIPE
			&& !get_next_relevant_token(token))
			return (-1);
		token = token->next;
	}
	return (0);
}


int				check_or(t_token *token)
{
	while (token)
	{
		if (token->type == DOUBLEPIPE
			&& !get_next_relevant_token(token))
			return (-1);
		token = token->next;
	}
	return (0);
}


int				check_and(t_token *token)
{
	while (token)
	{
		if (token->type == DOUBLEAND
			&& !get_next_relevant_token(token))
			return (-1);
		token = token->next;
	}
	return (0);
}

/*
** check_backslash :
** Retourne -1 si un back-slash suivi d'un '\n' est trouvé, sinon retourne 0.
*/

int				check_backslash(t_token *token)
{
	token = get_last_token(token);
	if (token->type == NEWLINE)
		return (0);
	ft_printf("--%c--\n", token->val[token->length - 1]);
	if (token->val[token->length - 1] == '\\')
		return (-1);
	return (0);
}

/*
** check_incomplete_command :
** Retourne l'inhibateur causant l'erreur.
*/

int		check_incomplete_command(t_token *token)
{
	char	quotetype;

	if (!token)
		return (COMPLETE);
	quotetype = check_quote(token);
	if (quotetype == '"')
		return (INC_DQUOTE);
	if (quotetype == '\'')
		return (INC_QUOTE);
	if (check_backslash(token) == -1)
		return (INC_BKSLASH);
	if (check_pipe(token) == -1)
		return (INC_PIPE);
	if (check_or(token) == -1)
		return (INC_DPIPE);
	if (check_and(token) == -1)
		return (INC_DAND);
	return (COMPLETE);
}
