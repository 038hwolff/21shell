/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:51:07 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 15:01:03 by hben-yah         ###   ########.fr       */
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
		if (!env[i] || !(path = ft_strsplit(env[i], ':')))
			return (NULL);
		path[0] = ft_strncpy(path[0], path[0] + 5, ft_strlen(path[0]));
		i = -1;
		while (path[++i])
		{
			tmp = path[i];
			if (!(path[i] = tristrjoin(path[i], "/", arg[0])))
				return (NULL);
			ft_strdel(&tmp);
		}
	}
	return (path ? path : ft_tabdup(&arg[0], 0));
}

int			ex_exec_core(char **env, char **table, char **paths)
{
	int		i;
	int		q;

	i = 0;
	while (paths[i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			if ((q = execve(paths[i], table, env)) == -1)
				;
			break ;
		}
		i++;
	}
	cmd_not_found_exception(*table);
	exit(1);
}

int			ex_exec(char **env, char **table)
{
	int		status;
	char	**paths;
	int		childpid;
	int		ret;

	if (!(paths = get_path(env, table)))
	{
		cmd_not_found_exception(*table);
		return (1);
	}
	ret = 0;
	childpid = fork();
	if (childpid == 0)
		ret = ex_exec_core(env, table, paths);
	else
		signal(SIGINT, SIG_IGN);
	wait(&status);
	free_tab(&paths);
	if (WIFSIGNALED(status))
	{
		ft_putchar('\n');
		return (WIFEXITED(status));
	}
	return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
}
