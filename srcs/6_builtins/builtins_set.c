/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:35:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/06 19:54:35 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		b_set(t_data *data, char **arg)
{
	char	*key;
	char	*value;
	int		i;

	if (!arg[(i = 1)])
	{
		ft_putstrtab(data->loc);
		ft_putstrtab(data->env);
		return (RET_OK);
	}
	while (arg[i])
	{
		if ((value = ft_strchr(arg[i], '=')))
		{
			try_m((key = ft_strsub(arg[i], 0, ++value - 1 - arg[i])));
			if (var_get_ptr(data->env, key))
				var_set(&data->env, key, value);
			else
				var_set(&data->loc, key, value);
			ft_strdel(&key);
		}
		++i;
	}
	return (RET_OK);
}
