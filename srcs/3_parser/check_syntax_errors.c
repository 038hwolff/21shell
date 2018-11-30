/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/22 23:11:04 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** ft_check_tokenerror :
** Check les erreurs de syntax.
** Renvoie une chaine de char correspondant au token responsable de l'erreur de
** syntaxe.
** Renvoie NULL si aucune erreur n'est trouvée.
*/

char		*check_syntax_errors(t_token *token)
{
	t_token	*next;

	if (token && is_control_op(token->type))
		return (token->val);
	while (token)
	{
		/*if (token->type == DSEMIC || token->type == CLOBBER
			|| token->type == LESSGREAT || token->type == DLESSDASH)
			return (token->val);*/
		if (is_redir_op(token->type) && token->next && token->next->type != WORD)
			return (token->next->val);
		if (is_agreg_op(token->type) && (!token->next || token->next->type != IO_NUMBER))
			return (token->next->val);
		if (is_control_op(token->type) && (next = get_next_relevant_token(token))
			&& is_control_op(next->type))
			return (next->val);
		token = token->next;
	}
	return (NULL);
}
