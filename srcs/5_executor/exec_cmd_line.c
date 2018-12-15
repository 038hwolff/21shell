/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:27:18 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/14 15:30:12 by hwolff           ###   ########.fr       */
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
	int rank;
	int ret;

	if (!ast)
		return (0);
	ret = 0;
	rank = get_rank(ast->token->type);
	if (rank == WORD)
		ret = ex_exec(data, ast);
	if (rank == ASSIGNEMENT_WORD)
		ret = set_local_var(data, ast);
	else if (rank == GREAT || rank == DOUBLEGREAT)
		ret = exec_redirect(data, ast, rank);
	else if (rank == LESS)
		ret = exec_back_redirect(data, ast);
	else if (rank == 3)
		ret = main_agregator(data, ast);
	else if (rank == 4)
		ret = exec_pipes(data, ast);
	else if (rank == 5 || rank == 6)
		ret = and_or(data, ast);
	else if (rank == 7)
		ret = execute_semicolon(data, ast);
	if (rank == 0)
		data->exe_return = ret;
	return (ret);
}
