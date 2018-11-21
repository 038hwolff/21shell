/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:42:16 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/21 15:47:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**	Est une erreur de syntaxe tout operateur en première position.
**  Tout opérateur non reconnu ou 
**  
*/
char		*check_syntax(t_token *tok)
{
	t_token	*next;

	if (tok && is_control_op(tok->type))
		return (tok->val);
	ft_printf("what ?");
	
	while (tok)
	{
		ft_printf("lal");
		//if (tok->type == DOUBLESEMICOLON || tok->type == GREATPIPE
		//	|| tok->type == LESSGREAT || tok->type == DOUBLELESSDASH)
		//	return (tok->val);
		if (is_redir_op(tok->type) && tok->next && tok->next->type != WORD)
			return (tok->next->val);
		if (is_agreg_op(tok->type) && (!tok->next || tok->next->type != IO_NUMBER))
			return (tok->next->val);
		if (is_control_op(tok->type) && (next = get_next_relevant_token(tok))
			&& is_control_op(next->type))
			return (next->val);
		tok = tok->next;
	}
	return (NULL);
}

/*
char		*ft_check_token(t_lexeme *lex)
{
	t_lexeme	*next_tok;

	if (lex && lex->token == CTRL_OP)
		return (lex->s);
	while (lex)
	{
		if (lex->op == DSEMIC || lex->op == CLOBBER
			|| lex->op == LESSGREAT || lex->op == DLESSDASH)
			return (lex->s);
		if (lex->token == RED_OP && lex->next && lex->next->token != WORD)
			return (lex->next->s);
		if (lex->token == CTRL_OP && (next_tok = ft_next_token(lex))
			&& next_tok->token == CTRL_OP)
			return (next_tok->s);
		lex = lex->next;
	}
	return (NULL);
}*/