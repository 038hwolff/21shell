/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:13:01 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/06 15:41:45 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_control_op(int op)
{
	return (op == PIPE
		|| op == AND
		|| op == DOUBLEPIPE
		|| op == DOUBLEAND
		|| op == SEMICOLON);
}

int		is_redir_op(int op)
{
	return (op == DOUBLELESS
		|| op == DOUBLEGREAT
		|| op == LESS
		|| op == GREAT);
}

int		is_agreg_op(int op)
{
	return (op == GREATAND
		|| op == LESSAND);
}

int		is_unsupported_op(int op)
{
	return (op == DOUBLESEMICOLON
		|| op == GREATPIPE
		|| op == LESSGREAT
		|| op == DOUBLELESSDASH
		|| op == AND);
}

int		is_word(int op)
{
	return (op == WORD
		|| op == ASSIGNEMENT_WORD);
}
