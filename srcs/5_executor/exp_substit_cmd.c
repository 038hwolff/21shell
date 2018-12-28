/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_substit_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 22:13:17 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/29 00:35:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*read_substit_result(int fd)
{
	char		buff[1025];
	int			len;
	char		*ret;
	char		*tmp;

	try_m((ret = ft_strnew(0)));
	ft_bzero((char *)buff, 1025);
	while ((len = read(fd, buff, 1024)) == 1024)
	{
		try_m((tmp = ft_strjoin(ret, buff)));
		ft_strdel(&ret);
		ret = tmp;
		ft_bzero((char *)buff, 1024);
	}
	try_m((tmp = ft_strjoin(ret, buff)));
	ft_strdel(&ret);
	ret = tmp;
	ft_bzero((char *)buff, len);
	return (ret);
}


static char		*get_substit_result(t_data *data, char *cmd)
{
	int		fd[2];
	int		std;
	pid_t	pid;
	int		status;
	char	*ret;

	ret = NULL;
	std = dup(1);
	if (!*cmd || (pipe(fd) == -1) || (pid = fork()) == -1)
		return (try_m(ft_strdup("")));
	else if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		exit(subshell(1, &cmd, data->env));
		// changer subshell en une version qui ne renvoie pas d'erreur
	}
	else if ((int)(pid = wait(&status)))
		ret = read_substit_result(fd[0]);
	dup2(fd[1], std);
	close(std);
	close(fd[0]);
	close(fd[1]);
	return (ret);
}

void		sustitute_cmd(char **str, char *sub, int start, int end)
{
	char *p1;
	char *p2;

	try_m((p1 = ft_strsub(*str, 0, start)));
	try_m((p2 = ft_strsub(*str, end, ft_strlen(*str))));
	ft_strdel(str);
	if (*p1 && *p2)
		ft_asprintf(str, "%s %s %s", p1, sub, p2);
	else if (*p1)
		ft_asprintf(str, "%s %s", p1, sub);
	else if (*p2)
		ft_asprintf(str, "%s %s", sub, p2);
	else
		*str = ft_strdup(sub);
	try_m(*str);
	ft_strdel(&p1);
	ft_strdel(&p2);
}

void			exp_substit_cmd(char **str, t_data *data)
{
	int		start;
	int		end;
	char	*cmd;
	char	*ret;

	start = 0;
	while ((*str)[start] && (*str)[start] != '`')
		++start;
	if ((*str)[++start] && (end = (strbackquote((*str) + start) - (*str) + 1)))
	{
		try_m((cmd = ft_strsub((*str), start, end - start - 1)));

		ft_printf("cmd : -%s-\n", cmd);
		ret = get_substit_result(data, cmd);
		ft_printf("ret : -%s-\n", ret);
		ft_strdel(&cmd);
		sustitute_cmd(str, ret, start - 1, end + 1);
		ft_printf("sub : -%s-\n", *str);
		ft_strdel(&ret);
	}
}
