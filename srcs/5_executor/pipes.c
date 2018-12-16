#include "shell.h"

static char	exec_next_cmd(t_data *data, t_ast *ast, int fildes[2], int std)
{
	char ret;

	dup2(fildes[0], 0);
	close(fildes[1]);
	//signal(SIGINT, SIG_IGN);
	//signal(SIGTSTP, SIG_IGN);
	ret = exec_cmd_line(data, ast->right);
	dup2(std, 0);
	close(std);
	exit(ret);
}

static char	exec_cmd(t_data *data, t_ast *ast, int fildes[2], int std)
{
	char ret;

	dup2(fildes[1], 1);
	close(fildes[0]);
	ret = exec_cmd_line(data, ast->left);
	dup2(std, 1);
	close(std);
	exit(ret);
}

static int		exec_one_pipe(t_data *data, t_ast *ast, int fildes[2], int std[2])
{
	int		ret;
	int		pid[2];
	int		stat[2];

	if ((pid[0] = fork()) == -1)
		return (!fork_exception());
	else if (!pid[0])
		ret = exec_next_cmd(data, ast, fildes, std[0]);
	if ((pid[1] = fork()) == -1)
		return (!fork_exception());
	else if (!pid[1])
		ret = exec_cmd(data, ast, fildes, std[1]);
	close(fildes[0]);
	close(fildes[1]);
	waitpid(pid[0], &stat[0], 0);
	waitpid(pid[1], &stat[1], 0);
	if ((WIFEXITED(stat[0])))
		return (WEXITSTATUS(stat[0]));
	return (WIFEXITED(stat[1]) ? WEXITSTATUS(stat[0]) : -1);
}

int				exec_pipes(t_data *data, t_ast *ast)
{
	int		fildes[2];
	int		std[2];
	if (pipe(fildes) == -1)
		return (!pipe_exception());
	std[0] = dup(0);
	std[1] = dup(1);
	return (exec_one_pipe(data, ast, fildes, std));
}
