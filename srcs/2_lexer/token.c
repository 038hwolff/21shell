/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:09:40 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/18 15:09:47 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token	*token_new(char *val, size_t length, int type, t_token *next)
{
	t_token *new;

	try_m((new = (t_token*)ft_memalloc(sizeof(t_token))));
	new->val = val;
	new->length = length;
	new->type = type;
	new->next = next;
	return (new);
}
