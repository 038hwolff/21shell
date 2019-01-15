/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_setenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:53:49 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/15 18:44:18 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		b_setenv(t_data *data, char **arg)
{
	char	*key;
	char	*value;
	int		i;

	i = 1;
	while (arg[i])
	{
		if ((value = ft_strchr(arg[i], '=')))
		{
			try_m((key = ft_strsub(arg[i], 0, ++value - 1 - arg[i])));
			var_set(&data->env, key, value);
			var_unset(&data->loc, key);
			ft_strdel(&key);
		}
		else
		{
			if ((value = var_get_val(data->loc, arg[i])))
			{
				var_set(&data->env, arg[i], value);
				var_unset(&data->loc, arg[i]);
			}
		}
		++i;
	}
	return (RET_OK);
}
