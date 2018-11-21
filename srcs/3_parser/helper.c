/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:41:33 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/21 15:46:27 by hben-yah         ###   ########.fr       */
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

t_token	*get_next_relevant_token(t_token *tok)
{
	tok = tok->next;
		ft_printf("gne\n");
	while (tok->next && tok->next->type == NEWLINE)
	{
		ft_printf("lol\n");
		tok = tok->next;
	}
	return (tok);
}