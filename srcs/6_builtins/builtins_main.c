/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:49:42 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/16 16:09:42 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_builtins(t_data *data, char **arg)
{
	if (data && arg)
	{
		if (ft_strcmp(*arg, "exit") == 0)
			b_exit();
		else if (ft_strcmp(*arg, "cd") == 0)
			b_cd(data, data->env, arg);
		else if (ft_strcmp(*arg, "echo") == 0)
			b_echo(arg);
		else if (ft_strcmp(*arg, "env") == 0)
			b_env(data->env, arg);
		else if (ft_strcmp(*arg, "setenv") == 0)
			b_setenv(&data->env, arg);
		else if (ft_strcmp(*arg, "unsetenv") == 0)
			b_unsetenv(data, arg);
		else
			return (0);
		return (1);
	}
	return (0);
}
