/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:16:44 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/16 20:03:13 by hwolff           ###   ########.fr       */
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
		if ((!ret && ast->token->type == DOUBLEAND)
			|| (ret && ast->token->type == DOUBLEPIPE))
		{
			if (ast->right)
				ret = exec_cmd_line(data, ast->right);
			else
				ret = 1;
		}
	}
	return (ret);
}
