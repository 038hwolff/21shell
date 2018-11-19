/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:49:42 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 19:28:28 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int     is_builtins(t_data *data)
{
    if (data)
    {
        if (ft_strcmp(data->args[0], "exit") == 0)
            b_exit(data);
        else if (ft_strcmp(data->args[0], "cd") == 0)
            b_cd(data);
        else if (ft_strcmp(data->args[0], "echo") == 0)
            b_echo(data);
        else if (ft_strcmp(data->args[0], "env") == 0)
            b_env(data);
        else if (ft_strcmp(data->args[0], "setenv") == 0)
            b_setenv(data);
        else if (ft_strcmp(data->args[0], "unsetenv") == 0)
            b_unsetenv(data);
        else
            return (0);
    }   
    return (1);
}
