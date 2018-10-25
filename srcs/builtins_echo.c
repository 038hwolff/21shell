/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:14:28 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/25 17:08:20 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

inline int     valid_flag_n(char *flag)
{
    int len;
    int j;

    len = ft_strlen(flag);
    j = 1;
    while (flag)
    {
        if (flag[j] != 'n')
            return (1);
        else
            j++;
    }
    return (2);
}

int     b_echo(t_built *built)
{
    int i;
    int j;

    if (built && built->av[1])
    {
        i = 1;
        if (ft_strncmp(built->av[1], "-n", 2) == 0)
            i = valid_flag_n(built->av[1]);
        while (built->av)
        {
            ft_putstr(built->av[i]);
            i++;
        }
        if (i == 1)
            ft_putchar('\n');
    }
    else
        return (0);
    return (1);
}