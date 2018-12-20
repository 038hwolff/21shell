/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:13:01 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/18 19:17:06 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_control_op(int op)
{
	return (op >= DOUBLEAND && op <= SEMICOLON);
}

int		is_redir_op(int op)
{
	return ((op >= DOUBLELESS && op <= DOUBLEGREAT)
			|| (op >= LESS && op <= GREAT));
}

int		is_agreg_op(int op)
{
	return (op == GREATAND);
}

int		is_unsupported_op(int op)
{
	return (op == DOUBLESEMICOLON || op == GREATPIPE
			|| op == LESSGREAT || op == DOUBLELESSDASH
			|| op == LESSAND || op == AND);
}
