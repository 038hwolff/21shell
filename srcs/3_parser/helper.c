/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:36:20 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/27 14:29:16 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_control_op(int i)
{
	return (i >= DOUBLEAND && i <= SEMICOLON);
}

int		is_redir_op(int i)
{
	return ((i >= DOUBLELESS && i <= DOUBLEGREAT)
			|| (i >= LESS && i <= GREAT));
}

int		is_agreg_op(int i)
{
	return (i >= LESSAND && i <= GREATAND);
}

t_token	*get_next_relevant_token(t_token *token)
{
	token = token->next;
	while (token && token->type == NEWLINE)
		token = token->next;
	return (token);
}

t_token	*get_last_token(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}
