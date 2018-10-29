/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:49:42 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/29 19:41:16 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int     is_builtins(t_built *built)
{
    if (built)
    {
        if (ft_strcmp(built->av[0], "exit") == 0)
            b_exit();
        // else if (ft_strcmp(built->av[0], "cd") == 0)
        //     b_cd(built);
        else if (ft_strcmp(built->av[0], "echo") == 0)
            b_echo(built);
        // else if (ft_strcmp(built->av[0], "env") == 0)
        //     b_env(built);
    }
    else
        return (0);
    return (1);
}