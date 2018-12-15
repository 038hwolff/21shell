/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:25:09 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/15 18:10:13 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		execute_semicolon(t_data *data, t_ast *ast)
{
	int ret;

	if (ast->left)
		ret = exec_cmd_line(data, ast->left);
	if (ast->right)
		ret = exec_cmd_line(data, ast->right);
	return (ret);
}
