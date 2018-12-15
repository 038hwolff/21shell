/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:25:09 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/14 17:30:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int execute_semicolon(t_data *data, t_ast *ast)
{
	int ret;

	if (ast->left)
		ret = execute(data, ast->left);
	if (ast->right)
		ret = execute(data, ast->right);
	return (ret);
}
