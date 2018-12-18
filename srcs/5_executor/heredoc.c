#include "shell.h"

static void	exec_heredoc_reading(
			t_data *data, t_ast *ast, int fildes[2], int std)
{
	int		ret;
	int		status;
	int		fd;

	fd = (ast->left_arg ? ft_atoi(ast->left_arg->val) : 0);
	dup2(fildes[0], fd);
	close(fildes[1]);
	wait(&status);
	ret = exec_cmd_line(data, ast->left);
	dup2(std, fd);
	close(std);
	exit(ret);
}

static void	exec_heredoc_writing(t_ast *ast, int fildes[2], int std)
{
	dup2(fildes[1], 1);
	close(fildes[0]);
	ft_dprintf(1, ast->token->heredoc);
	dup2(std, 1);
	close(std);
	exit(0);
}

static char	exec_heredoc_redir(
			t_data *data, t_ast *ast, int fildes[2], int std[2])
{
	int		pid[2];
	int		stat[2];

	if ((pid[0] = fork()) == -1)
		return (!fork_exception());
	else if (!pid[0])
		exec_heredoc_reading(data, ast, fildes, std[0]);
	if ((pid[1] = fork()) == -1)
		return (!fork_exception());
	else if (!pid[1])
		exec_heredoc_writing(ast, fildes, std[1]);
	close(fildes[0]);
	close(fildes[1]);
	waitpid(pid[0], &stat[0], 0);
	waitpid(pid[1], &stat[1], 0);
	if ((WIFEXITED(stat[0])))
		return (WEXITSTATUS(stat[0]));
	return (WIFEXITED(stat[1]) ? WEXITSTATUS(stat[0]) : -1);
}

int			exec_heredoc(t_data *data, t_ast *ast)
{
	int		fildes[2];
	int		std[2];

	if (pipe(fildes) == -1)
		return (!pipe_exception());
	std[0] = dup(0);
	std[1] = dup(1);
	return (exec_heredoc_redir(data, ast, fildes, std));
}
