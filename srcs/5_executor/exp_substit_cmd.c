/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_substit_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 22:13:17 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/16 17:27:12 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char
	*read_fd(int fd)
{
	char		buff[1025];
	int			len;
	int			tot;
	char		*ret;
	char		*tmp;

	try_m((ret = ft_strnew(0)));
	ft_bzero((char *)buff, 1025);
	tot = 0;
	while ((len = read(fd, buff, 1024)) == 1024)
	{
		buff[len] = 0;
		try_m((tmp = ft_strjoin(ret, buff)));
		ft_strdel(&ret);
		ret = tmp;
		tot += len;
	}
	buff[len] = 0;
	try_m((tmp = ft_strjoin(ret, buff)));
	ft_strdel(&ret);
	ret = tmp;
	tot += len;
	while (tot > 0 && ret[tot - 1] == '\n')
		ret[--tot] = 0;
	return (ret);
}

static char
	*get_substit_result(t_data *data, char *cmd)
{
	int		fd[2];
	int		std;
	pid_t	pid;
	int		status;
	char	*ret;

	std = dup(1);
	if (!*cmd || (pipe(fd) == -1) || (pid = fork()) == -1)
		return (try_m(ft_strdup("")));
	else if (pid == 0)
	{
		dup2(fd[1], 1);
		write(1, "=", 1);
		close(fd[1]);
		exit(++data->subcmd - 1 + subshell(data, 1, &cmd));
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	ret = read_fd(fd[0]);
	signal(SIGINT, signal_handler);
	dup2(fd[1], std);
	close(std);
	close(fd[0]);
	close(fd[1]);
	return (ret);
}

void
	sustitute_cmd(char **str, char *sub, int start, int end)
{
	char *p1;
	char *p2;

	try_m((p1 = ft_strsub(*str, 0, start)));
	try_m((p2 = ft_strsub(*str, end, ft_strlen(*str))));
	ft_strdel(str);
	ft_asprintf(str, "%s%s%s", p1, sub, p2);
	try_m(*str);
	ft_strdel(&p1);
	ft_strdel(&p2);
}

void
	exp_substit_cmd(char **str, t_data *data)
{
	char	*start;
	char	*end;
	char	*cmd;
	char	*ret;

	while (*(start = strbackquote(*str)) && *(start + 1))
	{
		if (!*(end = strbackquote(start + 1)))
			break ;
		try_m((cmd = ft_strsub(start, 1, end - start - 1)));
		ret = get_substit_result(data, cmd);
		ft_strdel(&cmd);
		sustitute_cmd(str, ret + 1, start - *str, end - *str + 1);
		ft_strdel(&ret);
	}
}
