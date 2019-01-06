/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:51:07 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/06 20:20:58 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		**get_path(char **env, char **arg)
{
	char	**path;
	int		i;
	char	*tmp;

	i = 0;
	if ((!(path = NULL) && arg[0][0] != '/')
			&& !(ft_strnequ(arg[0], "./", 2)))
	{
		while (env[i] && (ft_strncmp(env[i], "PATH=", 5) != 0))
			i++;
		if (!env[i] || !try_m(path = ft_strsplit(env[i], ':')))
			return (NULL);
		path[0] = ft_strncpy(path[0], path[0] + 5, ft_strlen(path[0]));
		i = -1;
		while (path[++i])
		{
			tmp = path[i];
			try_m((path[i] = ft_strjoin3(path[i], "/", arg[0])));
			ft_strdel(&tmp);
		}
	}
	return (path ? path : ft_strtabdup(&arg[0]));
}

int			ex_exec_core(char **env, char **table, char **paths)
{
	int		i;

	i = 0;
	while (paths[i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			if ((execve(paths[i], table, env)) == -1)
				;
			break ;
		}
		++i;
	}
	exit(put_exception(RET_NOT_FOUND, NULL, *table, "command not found"));
}

int			ex_exec(char **env, char **table)
{
	int		status;
	char	**paths;
	int		childpid;

	if (!(paths = get_path(env, table)))
	{
		put_exception(RET_NOT_FOUND, NULL, *table, "command not found");
		return (RET_NOT_FOUND);
	}
	if ((childpid = fork()) == -1)
		return (RET_MAJ_ERROR);
	if (childpid == 0)
		ex_exec_core(env, table, paths);
	else
		signal(SIGINT, SIG_IGN);
	wait(&status);
	free_tab(&paths);
	if (WIFSIGNALED(status))
	{
		ft_putchar('\n');
		return (WIFEXITED(status));
	}
	return (WIFEXITED(status) ? WEXITSTATUS(status) : RET_ERROR);
}
