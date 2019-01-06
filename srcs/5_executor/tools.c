/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:29:44 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/06 22:14:34 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		get_rank(int type)
{
	if (is_redir_op(type) || is_agreg_op(type))
		type = IO_NUMBER;
	if (type == ASSIGNEMENT_WORD || type == OPEN_PAR || type == CLOSED_PAR)
		type = WORD;
	return (type);
}

int		count_token(t_token *token)
{
	int		i;

	i = 0;
	while (token)
	{
		i++;
		token = token->next;
	}
	return (i);
}
