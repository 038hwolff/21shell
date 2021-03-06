/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:36:04 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/15 18:38:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		b_unset(t_data *data, char **args)
{
	int		i;

	i = 1;
	while (args[i])
	{
		var_unset(&data->env, args[i]);
		var_unset(&data->loc, args[i]);
		++i;
	}
	if (i == 1)
		return (put_exception(RET_OK, "unset", NULL, "not enough arguments"));
	return (RET_OK);
}
