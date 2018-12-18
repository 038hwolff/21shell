/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokendel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:14:20 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 18:50:40 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		token_is_empty(t_token *token)
{
	return (token->length == 0 && !*(token->val));
}

int		token_is_newline(t_token *token)
{
	return (token->type == NEWLINE);
}

void	tokendelone(t_token **elem)
{
	t_token	*todel;

	todel = *elem;
	*elem = (*elem)->next;
	ft_strdel(&todel->val);
	todel->type = 0;
	todel->next = NULL;
	todel->length = 0;
	ft_memdel((void**)&todel);
}

void	del_tokens_if(t_token **alst, int (*token_is)(t_token *))
{
	t_token	*current;

	if (!*alst)
		return ;
	current = *alst;
	while (current->next)
		if (token_is(current->next))
			tokendelone(&(current->next));
		else
			current = current->next;
	if (*alst && token_is(*alst))
		tokendelone(alst);
}
