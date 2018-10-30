/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:14:28 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 17:03:47 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int     valid_flag_n(char *flag)
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

int     b_echo(t_data *data)
{
    int i;

    if (data && data->args[1])
    {
        i = 1;
        if (ft_strncmp(data->args[1], "-n", 2) == 0)
            i = valid_flag_n(data->args[1]);
        while (data->args)
        {
            ft_putstr(data->args[i]);
            i++;
        }
        if (i == 1)
            ft_putchar('\n');
    }
    else
        return (0);
    return (1);
}