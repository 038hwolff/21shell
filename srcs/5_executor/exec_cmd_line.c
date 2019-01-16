/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:54:08 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/16 17:25:10 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** 7 - ; or &(jobs)
** 6 - ||
** 5 - &&
** 4 - |
** 3 - >&
** 2 - < or <<
** 1 - > or >>
** 0 - CMD
*/

static int
	sub_exec_cmd_line(t_data *data, t_ast *ast, int ret)
{
	if (ast->token->type == GREATAND)
		ret = main_agregator(data, ast);
	else if (ast->token->type == LESSAND)
		ret = main_back_agregator(data, ast);
	else if (ast->token->type == DOUBLELESS)
		ret = exec_heredoc(data, ast);
	else if (ast->token->type == PIPE)
		ret = exec_pipes(data, ast);
	else if (ast->token->type == DOUBLEPIPE || ast->token->type == DOUBLEAND)
		ret = and_or(data, ast);
	else if (ast->token->type == SEMICOLON)
		ret = execute_semicolon(data, ast);
	else if (ast->token->type == ASSIGNEMENT_WORD)
		ret = exec_assignement(data, ast);
	else if (ast->token->type == OPEN_PAR)
		ret = exec_subcmd(data, ast);
	return (ret);
}

int
	exec_cmd_line(t_data *data, t_ast *ast)
{
	int		ret;
	char	**table;

	if (!ast)
		return (RET_OK);
	if (ast->token->type != OPEN_PAR)
		expansion(data, ast->token);
	ret = RET_OK;
	if (ast->token->type == WORD && (table = tokens_to_tab(ast->token))
		&& (ret = is_builtins(data, table)) == -1)
		ret = ex_exec(data, data->env, table);
	else if (ast->token->type == GREAT || ast->token->type == DOUBLEGREAT)
		ret = exec_redirect(data, ast, ast->token->type);
	else if (ast->token->type == LESS)
		ret = exec_back_redirect(data, ast);
	else
		ret = sub_exec_cmd_line(data, ast, ret);
	if (ast->token->type == WORD)
	{
		var_set(&data->env, "_", table[ft_strtablen(table) - 1]);
		data->exe_return = ret;
		free_tab(&table);
	}
	return (ret);
}
