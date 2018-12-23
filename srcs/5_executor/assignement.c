/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:33:08 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/23 18:28:45 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		exec_assignement(t_data *data, t_ast *ast)
{
	int		ret;

	if (ast->token && ast->token->val)
		ret = var_set_line(&data->loc, ast->token->val);
	if (ast->right)
		ret = exec_cmd_line(data, ast->right);
	return (ret);
}
