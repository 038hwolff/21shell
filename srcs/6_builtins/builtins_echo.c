/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:14:28 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/16 15:50:33 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int     valid_flag_n(char **flag, int *i)
{
    int j;
    int state;

    state = 1;
    while (flag[*i])
    {
        j = 0;
        if (flag[*i][j] != '-')
            return (state);
        j = 1;
        while (flag[*i][j])
        {
            if (flag[*i][j] != 'n')
                return (state);
            j++;
        }
        state = 2;
        (*i)++;
    }
    return (state);
}

int     b_echo(char **arg)
{
    int i;
    int flag;

    if (arg[1])
    {
        i = 1;
        flag = valid_flag_n(arg, &i);
        while (arg[i])
        {
            ft_printf(arg[i]);
            if (arg[++i])
                ft_putchar(' ');
        }
        if (flag == 1)
            ft_putchar('\n');
    }
    return (1);
}
