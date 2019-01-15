/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:46:19 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/15 18:24:00 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token *tokendup(t_token *tok)
{
	t_token *new;

	try_m(new = ft_memalloc(sizeof(t_token)));
	if (tok->val)
		try_m(new->val = ft_strdup(tok->val));
	new->length = tok->length;
	new->type = tok->type;
	if (tok->heredoc)
		try_m(new->heredoc = ft_strdup(tok->heredoc));
	new->next = NULL;
	return (new);
}

void	tokendel(t_token **tok)
{
	t_token *todel;

	todel = *tok;
	*tok = (*tok)->next;
	if (todel->val)
		ft_strdel(&todel->val);
	if (todel->heredoc)
		ft_strdel(&todel->heredoc);
	todel->next = NULL;
	free(todel);
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
	pop_par(t_token *chosen, t_token **chosen_prev)
{
	t_token *dtok;

	if (chosen->type == OPEN_PAR)
	{
		dtok = chosen;
		while (dtok->type != CLOSED_PAR)
			dtok = dtok->next;
		
		if (*chosen_prev)
			(*chosen_prev)->next = dtok->next;
		dtok->next = NULL;
	}
	else if (chosen->type == WORD)
	{
		dtok = chosen;
		while (dtok->next && is_word(dtok->next->type))
			dtok = dtok->next;
		if (*chosen_prev)
			(*chosen_prev)->next = dtok->next;
		dtok->next = NULL;
	}
}

static void
	fill_node(t_ast **ast, t_token **chosen, t_token **prev)
{
	try_m((*ast = (t_ast*)ft_memalloc(sizeof(t_ast))));
	if ((*chosen)->type == OPEN_PAR || (*chosen)->type == WORD)
	{
		(*ast)->token = *chosen;
		pop_par(*chosen, prev);
		*chosen = NULL;
	}
	else if ((*chosen)->type == IO_NUMBER)
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
		*chosen = NULL;
	}
	else if (is_redir_op((*chosen)->type) || is_agreg_op((*chosen)->type))
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
		*chosen = NULL;
	}
	else
	{
		(*ast)->token = tokendup(*chosen);
		tokendel(chosen);
		if (*prev)
			(*prev)->next = NULL;
	}
}

// static void
// 	pop_chosen_from_token_if_redir(t_token **chosen, t_token **chosen_prev,
// 								t_token **token, int type)
// {
// 	t_token *dtok;

// 	dtok = (*chosen);
// 	// si c'est une parenthese on englobe jusauq la par fermante
// 	if (type == OPEN_PAR)
// 		while (dtok->type != CLOSED_PAR)
// 			dtok = dtok->next;
// 	// pour toutes les redir on colle le next de la redir au next du token precedent
// 	// on recolle la liste apres a voir retirer le ou les tokens de la redir ou de la par
// 	if (*chosen && (is_redir_op(type) || is_agreg_op(type) || type == OPEN_PAR))
// 	{
// 		if (*chosen_prev)
// 			(*chosen_prev)->next = dtok->next;
// 		else
// 			*token = dtok->next;
// 		dtok->next = NULL;
// 	}
// }

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
	fill_node(ast, &chosen, &chosen_prev);
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
