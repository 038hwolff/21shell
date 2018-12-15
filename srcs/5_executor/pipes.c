/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:07:57 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/14 11:48:52 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int      error_forkpipe(char *coderr)
{
    if (ft_strcmp(coderr, "misspipe") == 0)
        ft_putstr("pipe> ");
    else if (ft_strcmp(coderr, "error") == 0)
        ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"error -- %s\n");
    return (-1);
}

static int      exec_one_pipe(t_data *data, int fildes[2], t_ast *ast, int pid)
{
    int ret;

    if (pid == 0)
    {
        dup2(fildes[0], 0);
        close(fildes[1]);
        ret = execute(data, ast->right);
        exit(EXIT_SUCCESS);
    }
    else
    {
        dup2(fildes[1], 1);
        close(fildes[0]);
        ret = execute(data, ast->left);
        wait(NULL);
    }
    return (ret);
}

int             exec_pipes(t_data *data, t_ast *ast)
{
    int     fildes[2];
    pid_t   pid;

    pid = fork();
    if (pid < 0 || pipe(fildes) == -1)
        return (error_forkpipe("error"));
    exec_one_pipe(data, &fildes[2], ast, pid);
    return (0);
}
