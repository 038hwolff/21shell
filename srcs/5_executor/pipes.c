/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:07:57 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/13 19:06:10 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int      exec_one_pipe(t_data *data, int fildes[2], t_ast *ast, int pid)
{
    char    buf;

    if (pid == 0)
    {
        dup2(fildes[0], 0);
        close(fildes[1]);
        execute(data, ast->right);
        exit(EXIT_SUCCESS);
    }
    else
    {
        dup2(fildes[1], 1);
        close(fildes[0]);
        execute(data, ast->left);
        wait(NULL);
    }
}

int             exec_pipes(t_data *data, t_ast *ast)
{
    int     fildes[2];
    pid_t   pid;
    int     status;

    pid = fork();
    if (pid < 0 || pipe(fildes) == -1)
        return (error_forkpipe("error"));
    exec_one_pipe(data, &fildes[2], ast, pid);
    return (0);
}
