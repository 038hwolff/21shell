/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:16:44 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/16 15:39:21 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		and_or(t_data *data, t_ast *ast)
{
	int ret;

	ret = 0;
	if (ast->left)
	{
		ret = exec_cmd_line(data, ast->left);
		ft_printf("%d\n", ret);
		if ((!ret && ast->token->type == DOUBLEAND) ||
			(ret && ast->token->type == DOUBLEPIPE))
		{
			if (ast->right)
				ret = exec_cmd_line(data, ast->right);
			else
				ret = 1;
		}
	}
	return (ret);
}
