/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:49:42 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/23 16:41:46 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_builtins(t_data *data, char **arg)
{
	if (data && arg)
	{
		if (ft_strequ(*arg, "exit"))
			b_exit();
		else if (ft_strequ(*arg, "cd"))
			b_cd(data, data->env, arg);
		else if (ft_strequ(*arg, "echo"))
			b_echo(arg);
		else if (ft_strequ(*arg, "env"))
			b_env(data, arg);
		else if (ft_strequ(*arg, "setenv"))
			b_setenv(data, arg);
		else if (ft_strequ(*arg, "unsetenv"))
			b_unsetenv(data, arg);
		else if (ft_strequ(*arg, "unset"))
			b_unset(data, arg);
		else if (ft_strequ(*arg, "export"))
			b_export(data, arg);
		else if (ft_strequ(*arg, "set"))
			b_set(data, arg);
		else
			return (0);
		return (1);
	}
	return (0);
}
