/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:24:23 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/06 15:27:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		b_export(t_data *data, char **arg)
{
	char	*key;
	char	*value;
	int		i;

	i = 1;
	while (arg[i])
	{
		value = ft_strchr(arg[i], '=');
		if (value)
		{
			try_m((key = ft_strsub(arg[i], 0, value - arg[i])));
			++value;
			var_set(&data->env, key, value);
			var_unset(&data->loc, key);
			ft_strdel(&key);
		}
		else
		{	
			value = var_get_val(data->loc, arg[i]);
			if (value)
			{
				var_set(&data->env, arg[i], value);
				var_unset(&data->loc, arg[i]);
			}
		}
		i++;
	}
	return (RET_OK);
}
