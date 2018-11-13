/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:08:32 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/13 18:08:36 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int     exec_one_redirect(t_data *data, int file[], int rafter)
{
    char    buf;
    int     ret;
    pid_t   pid;
    
    if (rafter == 1)
        ret = open(data->args[2], O_CREAT|O_WRONLY, 0666);
    else if (rafter == 2)
        ret = open(data->args[2], O_APPEND);
    if (ret >= 0)
    {
        pid = fork();
        dup2(file[2], 1);
        close(file[2]);
         while (read(file[1], &buf, 1) > 0)
            write(file[2], &buf, 1);
        write(STDOUT_FILENO, "\n", 1);
        is_builtins(data);
    }
    else
    {
        ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"error -- %s\n");
        exit(EXIT_FAILURE);
    }
    return (0);
}