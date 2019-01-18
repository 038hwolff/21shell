/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:33:08 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/18 14:43:25 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		exec_assignement(t_data *data, t_ast *ast)
{
	int		ret;
	char	*key;
	char	*val;

	if (ast->token && ast->token->val)
	{
		val = ft_strchr(ast->token->val, '=');
		ret = val ? !var_set_line(&data->loc, ast->token->val) : 1;
	}
	if (ast->right)
	{
		ret = exec_cmd_line(data, ast->right);
		if (ast->token && ast->token->val)
		{
			try_m(key = ft_strsub(ast->token->val, 0,
							val ? val - ast->token->val : ast->token->length));
			var_unset(&data->loc, key);
			ft_strdel(&key); 
		}
	}
	return (ret);
}
