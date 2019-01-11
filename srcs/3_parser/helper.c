/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:36:20 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/11 21:10:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token		*get_next_relevant_token(t_token *token)
{
	token = token->next;
	while (token && token->type == NEWLINE)
		token = token->next;
	return (token);
}

t_token		*get_last_token(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

void		append_token_value(t_token *token, int i, char **line)
{
	char	*head;
	char	*tail;

	try_m((tail = ft_strsub(*line, 0, i)));
	head = token->val;
	try_m((token->val = ft_strjoin(head, tail)));
	token->length += i;
	ft_strdel(&head);
	ft_strdel(&tail);
	try_m((tail = ft_strdup(*line + i)));
	ft_strdel(line);
	*line = tail;
}

void		merge_tokens(t_token *t1, t_token *t2)
{
	char *tmp;

	if (t1 && t2)
	{
		tmp = t1->val;
		try_m((t1->val = ft_strjoin(tmp, t2->val)));
		t1->length += t2->length;
		ft_strdel(&tmp);
		ft_strdel(&t2->val);
		t1->next = t2->next;
		ft_memdel((void**)&t2);
	}
}

int			put_eof_exception(t_data *data)
{
	put_exception(0, data->subcmd ? "command substitution" : NULL,
				NULL, "unexpected end of file");
	return (RET_OK);
}
