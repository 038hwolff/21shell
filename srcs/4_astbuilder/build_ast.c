/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:46:19 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/24 00:11:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void
	fill_node_io_number(t_ast **ast, t_token **chosen,
										t_token **prev, t_token **beginlist)
{
	(*ast)->left_arg = tokendup(*chosen);
	tokendel(chosen);
	(*ast)->token = tokendup(*chosen);
	tokendel(chosen);
	if (*chosen
		&& ((*chosen)->type == IO_NUMBER
		|| (*chosen)->type == WORD))
	{
		(*ast)->right_arg = tokendup(*chosen);
		tokendel(chosen);
	}
	if (*prev)
		(*prev)->next = *chosen;
	else
		*beginlist = *chosen;
	*chosen = NULL;
}

static void
	fill_node_redir_agreg(t_ast **ast, t_token **chosen,
										t_token **prev, t_token **beginlist)
{
	(*ast)->token = tokendup(*chosen);
	tokendel(chosen);
	if (*chosen)
	{
		(*ast)->right_arg = tokendup(*chosen);
		tokendel(chosen);
	}
	if (*prev)
		(*prev)->next = *chosen;
	else
		*beginlist = *chosen;
	*chosen = NULL;
}

static void
	fill_node(t_ast **ast, t_token **chosen,
										t_token **prev, t_token **beginlist)
{
	try_m((*ast = (t_ast*)ft_memalloc(sizeof(t_ast))));
	if ((*chosen)->type == OPEN_PAR || (*chosen)->type == WORD)
	{
		(*ast)->token = *chosen;
		pop_par(*chosen, prev);
		*chosen = NULL;
	}
	else if ((*chosen)->type == IO_NUMBER)
		fill_node_io_number(ast, chosen, prev, beginlist);
	else if (is_redir_op((*chosen)->type) || is_agreg_op((*chosen)->type))
		fill_node_redir_agreg(ast, chosen, prev, beginlist);
	else
	{
		(*ast)->token = tokendup(*chosen);
		tokendel(chosen);
		if (*prev)
			(*prev)->next = NULL;
	}
}

static void
	add_node(t_data *data, t_ast **ast, t_token *beginlist1)
{
	t_token *chosen_prev;
	t_token *chosen;
	int		type;

	if (!ast || !beginlist1)
		return ;
	chosen_prev = NULL;
	if (!(chosen = get_primary_prev_token(&chosen_prev, beginlist1)))
		return ;
	type = chosen->type;
	if (chosen_prev)
		chosen_prev->next = NULL;
	else
		beginlist1 = NULL;
	fill_node(ast, &chosen, &chosen_prev, &beginlist1);
	if (beginlist1)
		add_node(data, &(*ast)->left, beginlist1);
	if (chosen)
		add_node(data, &(*ast)->right, chosen);
}

void
	build_ast(t_data *data)
{
	if (data->token)
		add_node(data, &data->ast, data->token);
	data->token = NULL;
}
