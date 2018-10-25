/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:49:42 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/25 15:16:20 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

int     is_builtins(t_built *built)
{
    if (built)
    {
        if (ft_strcmp(built->av[0], "exit") == 0)
            b_exit();
        else if (ft_strcmp(built->av[0], "cd") == 0)
            b_cd(built);
        else if (ft_strcmp(built->av[0], "echo") == 0)
            b_echo(built);
        else if (ft_strcmp(built->av[0], "env") == 0)
            b_env(built);
    }
    else
        return (0);
    return (1);
}