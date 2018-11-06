/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:07:57 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/06 16:22:08 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int     error_forkpipe(char *fct)
{
    // free();
    ft_putstr(&fct);
    ft_putendl(" error");
    return (-1);
}

int     exec_pipes(t_data *data)
{
    int fd1;
    int fd2;
    int fildes[2];
    int pid;

    fildes[0] = fd1;
    fildes[1] = fd2;
    if (pipe(fildes) == -1)
        return (error_forkpipe("Pipe"));
    pid = fork();
    if (pid < 0)
        return (error_forkpipe("Fork"));

}