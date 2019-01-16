/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:54:30 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/16 17:56:08 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token
	*tokendup(t_token *tok)
{
	t_token *new;

	try_m(new = ft_memalloc(sizeof(t_token)));
	if (tok->val)
		try_m(new->val = ft_strdup(tok->val));
	new->length = tok->length;
	new->type = tok->type;
	if (tok->heredoc)
		try_m(new->heredoc = ft_strdup(tok->heredoc));
	new->next = NULL;
	return (new);
}

void
	tokendel(t_token **tok)
{
	t_token *todel;

	todel = *tok;
	*tok = (*tok)->next;
	if (todel->val)
		ft_strdel(&todel->val);
	if (todel->heredoc)
		ft_strdel(&todel->heredoc);
	todel->next = NULL;
	free(todel);
}

t_token
	*get_primary_prev_token(t_token **primary_prev, t_token *token)
{
	t_token *primary;
	t_token *tmp;

	if (!token)
		return (NULL);
	primary = token;
	tmp = NULL;
	while (token)
	{
		if (get_rank(token->type) > get_rank(primary->type))
		{
			*primary_prev = tmp;
			primary = token;
		}
		if (token->type == OPEN_PAR)
			while (token && token->type != CLOSED_PAR)
				token = token->next;
		if (token)
		{
			tmp = token;
			token = token->next;
		}
	}
	return (primary);
}

void
	pop_par(t_token *chosen, t_token **chosen_prev)
{
	t_token *dtok;

	if (chosen->type == OPEN_PAR)
	{
		dtok = chosen;
		while (dtok->type != CLOSED_PAR)
			dtok = dtok->next;
		if (*chosen_prev)
			(*chosen_prev)->next = dtok->next;
		dtok->next = NULL;
	}
	else if (chosen->type == WORD)
	{
		dtok = chosen;
		while (dtok->next && is_word(dtok->next->type))
			dtok = dtok->next;
		if (*chosen_prev)
			(*chosen_prev)->next = dtok->next;
		dtok->next = NULL;
	}
}
