
#include "shell.h"

int
	get_rank(int type)
{
	if (type >= IO_NUMBER && type <= GREATAND)
		type = IO_NUMBER;
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
		tmp = token;
		token = token->next;
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
	else if (is_redir_op((*chosen)->type))
	{
		(*ast)->right_arg = (*chosen)->next;
		*chosen = (*chosen)->next;
	}
}

static void
	add_node(t_data *data, t_ast **ast, t_token *token)
{
	t_token *chosen_prev;
	t_token *chosen;
	int		type;

	expansion(data, token);
	chosen_prev = NULL;
	if (!token)
		return ;
	chosen = get_primary_prev_token(&chosen_prev, token);
	if (chosen_prev)
		chosen_prev->next = NULL;
	else
		token = NULL;
	type = chosen->type;
	fill_node(ast, &chosen);
	if (is_redir_op(type))
	{
		if (chosen_prev)
			chosen_prev->next = chosen->next;
		else
			token = chosen->next;
		chosen->next = NULL;
	}
	if (token)
		add_node(data, &(*ast)->left, token);
	if (chosen->next)
		add_node(data, &(*ast)->right, chosen->next);
}

void
	build_ast(t_data *data)
{
	if (data->token)
		add_node(data, &data->ast, data->token);
}
