/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:14:28 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 19:12:52 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

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

int     b_echo(t_data *data)
{
    int i;
    int flag;

    if (data && data->args[1])
    {
        i = 1;
        flag = valid_flag_n(data->args, &i);
        while (data->args[i])
        {
            ft_putstr(data->args[i]);
            if (data->args[++i])
                ft_putchar(' ');
        }
        if (flag == 1)
            ft_putchar('\n');
    }
    else
        return (0);
    return (1);
}