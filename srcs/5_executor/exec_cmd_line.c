/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:27:18 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/14 18:57:19 by hben-yah         ###   ########.fr       */
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

int     execute(t_data *data, t_ast *ast)
{
	int ret;

	if (!ast)
		return (0);
	ret = 0;
	if (ast->token->type == WORD)
		ret = ex_exec(data, ast);
	if (ast->token->type == ASSIGNEMENT_WORD)
		ret = set_local_var(data, ast);
	else if (ast->token->type == GREAT || ast->token->type == DOUBLEGREAT)
		ret = exec_redirect(data, ast, ast->token->type);
	else if (ast->token->type == LESS)
		ret = exec_back_redirect(data, ast);
	else if (ast->token->type == GREATAND)
		ret = main_agregator(data, ast);
	else if (ast->token->type == PIPE)
		ret = exec_pipes(data, ast);
	else if (ast->token->type == DOUBLEPIPE || ast->token->type == DOUBLEAND)
		ret = and_or(data, ast);
	else if (ast->token->type == SEMICOLON)
		ret = execute_semicolon(data, ast);
	if (ast->token->type == WORD)
		data->exe_return = ret;
	return (ret);
}
