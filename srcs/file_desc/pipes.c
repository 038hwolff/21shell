/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:07:57 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/07 19:21:42 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*static int  error_forkpipe(char *coderr)
{
    // free();
    if (coderr == "misspipe")
        ft_putstr("pipe> ");
    else if (coderr == "error")
        ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"error -- %s\n");
    return (-1);
}

static int  exec_one_pipe(t_data *data, int fildes[2], int pid)
{
    char    buf;

    if (pid == 0)
    {
        dup2(fildes[0], 0);
        close(fildes[1]);
        while (read(fildes[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);
        write(STDOUT_FILENO, "\n", 1);
        close(fildes[0]);  
    }
    else
    {
        dup2(fildes[1], 1);
        close(fildes[0]);
        write(fildes[1], data->args[1], ft_strlen(data->args[1]));
        close(fildes[1]);
        wait(NULL);
    }
    exit(EXIT_SUCCESS);
}

static int  exec_sev_pipes(t_data *data, int fildes[], int pid)
{
    int     i;
    char    buf;

    if (pid == 0)
    {

    }
    else
    {

    }
    exit(EXIT_SUCCESS);
}

int         exec_pipes(t_data *data, int nb)
{
    int     fildes[nb * 2];
    int     pid;
    char    buf;

    pid = fork();
    if (pid < 0 || pipe(fildes) == -1)
        return (error_forkpipe("error"));
    if (nb == 2)
        exec_one_pipe(data, fildes[2], pid);
    else if (nb > 2)
        exec_sev_pipes(data, fildes[nb * 2], pid);
    else
    {
        error_forkpipe("misspipe");
        exit(EXIT_FAILURE);
    }
    return (0);
}*/
