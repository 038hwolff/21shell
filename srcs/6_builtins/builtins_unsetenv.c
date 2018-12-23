/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unsetenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:36:43 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/23 18:12:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

// void	ft_rmvline(int j, t_data *data)
// {
// 	ft_strdel(data->env + j);
// 	while (data->env[j + 1])
// 	{
// 		data->env[j] = data->env[j + 1];
// 		data->env[j + 1] = NULL;
// 		j++;
// 	}
// }

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
	return (1);
}
