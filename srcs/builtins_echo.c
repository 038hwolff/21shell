/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:14:28 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/25 15:08:42 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

int     b_echo(t_built *built)
{
    int i;
    int j;

    if (built)
    {
        if (ft_strncmp(built->av[1], "-", 1) == 0)
        {

        }
        while (built->av)
        {
            ft_putstr(built->av[i]);
            i++;
        }
        
    }
    else
        return (0);
    return (1);
}