/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unsetenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:36:43 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/06 14:03:05 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		b_unsetenv(t_data *data, char **arg)
{
	int		i;

	i = 1;
	while (arg[i])
	{
		if (var_get_ptr(data->env, arg[i]))
			var_unset(&data->env, arg[i]);
		i++;
	}
	return (RET_OK);
}
