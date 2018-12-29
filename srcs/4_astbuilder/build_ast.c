/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:46:19 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/29 22:20:10 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int
	get_rank(int type)
{
	if (type >= IO_NUMBER && type <= GREATAND)
		type = IO_NUMBER;
	if (type == ASSIGNEMENT_WORD || type == OPEN_PAR || type == CLOSED_PAR)
		type = WORD;
	return (type);
}

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
		if (*chosen && (*chosen)->next
			&& ((*chosen)->next->type == IO_NUMBER
			|| (*chosen)->next->type == WORD))
		{
			(*ast)->right_arg = (*chosen)->next;
			*chosen = (*chosen)->next;
		}
	}
	else if (is_redir_op((*chosen)->type) || is_agreg_op((*chosen)->type))
	{
		if ((*chosen)->next)
		{
			(*ast)->right_arg = (*chosen)->next;
			*chosen = (*chosen)->next;
		}
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
	expansion(data, token);
	chosen_prev = NULL;
	chosen = get_primary_prev_token(&chosen_prev, token);
	if (chosen_prev)
		chosen_prev->next = NULL;
	else
		token = NULL;
	type = chosen->type;
	fill_node(ast, &chosen);
	if (type == OPEN_PAR)
		while (chosen && chosen->type != CLOSED_PAR)
			chosen = chosen->next;
	if (chosen && (is_redir_op(type) || is_agreg_op(type)))
	{
		if (chosen_prev)
			chosen_prev->next = chosen->next;
		else
			token = chosen->next;
		chosen->next = NULL;
	}
	add_node(data, &(*ast)->left, token);
	if (chosen)
		add_node(data, &(*ast)->right, chosen->next);
}

void
	build_ast(t_data *data)
{
	if (data->token)
		add_node(data, &data->ast, data->token);
}
