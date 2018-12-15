/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:25:09 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/15 09:45:06 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		execute_semicolon(t_data *data, t_ast *ast)
{
	int ret;

	if (ast->left)
		ret = execute(data, ast->left);
	if (ast->right)
		ret = execute(data, ast->right);
	return (ret);
}
