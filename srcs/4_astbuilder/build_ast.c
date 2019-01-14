/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:46:19 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/14 14:16:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_token
	*get_primary_prev_token(t_token **primary_prev, t_token *token)
{
	t_token *primary;
	t_token *tmp;

	if (!token)
		return (NULL);
	primary = token;
	tmp = NULL;
	while (token)
	{
		if (get_rank(token->type) > get_rank(primary->type))
		{
			*primary_prev = tmp;
			primary = token;
		}
		if (token->type == OPEN_PAR)
			while (token && token->type != CLOSED_PAR)
				token = token->next;
		if (token)
		{
			tmp = token;
			token = token->next;
		}
	}
	return (primary);
}

static void
	fill_node(t_ast **ast, t_token **chosen)
{
	try_m((*ast = (t_ast*)ft_memalloc(sizeof(t_ast))));
	(*ast)->token = *chosen;
	(*ast)->type = (*chosen)->type;
	if ((*chosen)->type == IO_NUMBER)
	{
		(*ast)->left_arg = (*chosen);
		(*ast)->token = (*chosen)->next;
		*chosen = (*chosen)->next;
		(*ast)->left_arg->next = NULL;
		if (*chosen && (*chosen)->next
			&& ((*chosen)->next->type == IO_NUMBER
			|| (*chosen)->next->type == WORD))
		{
			(*ast)->right_arg = (*chosen)->next;
			(*ast)->right_arg->next = NULL;
			*chosen = (*chosen)->next;
		}
	}
	else if (is_redir_op((*chosen)->type) || is_agreg_op((*chosen)->type))
	{
		if ((*chosen)->next)
		{
			(*ast)->right_arg = (*chosen)->next;
			*chosen = (*chosen)->next;
			(*ast)->right_arg->next = NULL;
		}
	}
}

static void
	pop_chosen_from_token_if_redir(t_token **chosen, t_token **chosen_prev,
								t_token **token, int type)
{
	t_token *dtok;

	dtok = (*chosen);
	if (type == OPEN_PAR)
		while (dtok->type != CLOSED_PAR)
			dtok = dtok->next;
	if (*chosen && (is_redir_op(type) || is_agreg_op(type) || type == OPEN_PAR))
	{
		if (*chosen_prev)
			(*chosen_prev)->next = dtok->next;
		else
			*token = dtok->next;
		dtok->next = NULL;
	}
}

static void
	add_node(t_data *data, t_ast **ast, t_token *token)
{
	t_token *chosen_prev;
	t_token *chosen;
	int		type;

	if (!token)
		return ;
	chosen_prev = NULL;
	chosen = get_primary_prev_token(&chosen_prev, token);
	if (chosen_prev)
		chosen_prev->next = NULL;
	else
		token = NULL;
	type = chosen->type;
	fill_node(ast, &chosen);
	pop_chosen_from_token_if_redir(&chosen, &chosen_prev, &token, type);
	add_node(data, &(*ast)->left, token);
	if (chosen && type != WORD && type != OPEN_PAR)
	{
		add_node(data, &(*ast)->right, chosen->next);
		(*ast)->token->next = NULL;
	}
}

void
	build_ast(t_data *data)
{
	if (data->token)
		add_node(data, &data->ast, data->token);
	data->token = NULL;
}
