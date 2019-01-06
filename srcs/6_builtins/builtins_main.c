/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:49:42 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/06 19:53:44 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_builtins(t_data *data, char **arg)
{
	if (data && arg && *arg)
	{
		if (ft_strequ(*arg, "exit"))
			return (b_exit(data, arg));
		if (ft_strequ(*arg, "cd"))
			return (b_cd(data, data->env, arg));
		if (ft_strequ(*arg, "echo"))
			return (b_echo(arg));
		if (ft_strequ(*arg, "env"))
			return (b_env(data, arg));
		if (ft_strequ(*arg, "setenv"))
			return (b_setenv(data, arg));
		if (ft_strequ(*arg, "unsetenv"))
			return (b_unsetenv(data, arg));
		if (ft_strequ(*arg, "unset"))
			return (b_unset(data, arg));
		if (ft_strequ(*arg, "export"))
			return (b_export(data, arg));
		if (ft_strequ(*arg, "set"))
			return (b_set(data, arg));
	}
	return (-1);
}
