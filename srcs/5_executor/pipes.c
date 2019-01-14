/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:57:00 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/14 16:21:07 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void
	exec_next_cmd(t_data *data, t_ast *ast, int fildes[2], int std)
{
	int		ret;

	dup2(fildes[0], 0);
	close(fildes[1]);
	ret = exec_cmd_line(data, ast->right);
	dup2(std, 0);
	close(std);
	exit(ret);
}

static void
	exec_cmd(t_data *data, t_ast *ast, int fildes[2], int std)
{
	int		ret;

	dup2(fildes[1], 1);
	close(fildes[0]);
	ret = exec_cmd_line(data, ast->left);
	dup2(std, 1);
	close(std);
	exit(ret);
}

static int
	exec_one_pipe(t_data *data, t_ast *ast, int fildes[2], int std[2])
{
	int		pid[2];
	int		stat[2];

	if ((pid[0] = fork()) == -1)
		return (put_exception(RET_ERROR, NULL, NULL, "fork error"));
	else if (!pid[0])
		exec_next_cmd(data, ast, fildes, std[0]);
	if ((pid[1] = fork()) == -1)
		return (put_exception(RET_ERROR, NULL, NULL, "fork error"));
	else if (!pid[1])
		exec_cmd(data, ast, fildes, std[1]);
	signal(SIGINT, SIG_IGN);
	close(fildes[0]);
	close(fildes[1]);
	waitpid(pid[0], &stat[0], 0);
	waitpid(pid[1], &stat[1], 0);
	signal(SIGINT, signal_handler);
	if ((WIFEXITED(stat[0])))
		return (WEXITSTATUS(stat[0]));
	return (WIFEXITED(stat[1]) ? WEXITSTATUS(stat[1]) : RET_ERROR);
}

int
	exec_pipes(t_data *data, t_ast *ast)
{
	int		fildes[2];
	int		std[2];

	if (pipe(fildes) == -1)
		return (put_exception(RET_ERROR, NULL, NULL, "pipe error"));
	std[0] = dup(0);
	std[1] = dup(1);
	return (exec_one_pipe(data, ast, fildes, std));
}
