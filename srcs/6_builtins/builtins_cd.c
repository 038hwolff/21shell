/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:29:51 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/06 20:27:14 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		setenv_cd(char **arg, char *env1, char *env2)
{
	if (env1)
	{
		chdir(env1);
		try_m((arg[1] = ft_strjoin("PWD=", env1)));
	}
	if (env2)
		try_m((arg[2] = ft_strjoin("OLDPWD=", env2)));
	return (RET_OK);
}

static int		change_dir(char *path, char **arg, char **cdenv)
{
	char	*buff;

	if (access(path, F_OK) != 0)
	{
		put_exception(RET_ERROR, "cd", path, "No such file or directory");
		return (RET_ERROR);
	}
	if (access(path, X_OK) != 0)
		return (put_exception(RET_ERROR, "cd", path, "Permission denied"));
	buff = NULL;
	chdir(path);
	try_m(buff = getcwd(buff, 0));
	try_m(arg[1] = ft_strjoin("PWD=", buff));
	try_m(arg[2] = ft_strjoin("OLDPWD=", cdenv[2]));
	ft_strdel(&buff);
	return (RET_OK);
}

static void		init_cdenv(char **cdenv, char **env)
{
	int		i;

	i = 0;
	cdenv[0] = NULL;
	cdenv[1] = NULL;
	cdenv[2] = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
			cdenv[0] = env[i] + 5;
		else if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
			cdenv[1] = env[i] + 7;
		else if (ft_strncmp(env[i], "PWD=", 4) == 0)
			cdenv[2] = env[i] + 4;
		i++;
	}
}

static void		free_cd_tabs(char **tmp, char **nenv, char **narg)
{
	free_tab(&tmp);
	free_tab(&nenv);
	free_tab(&narg);
}

int				b_cd(t_data *data, char **env, char **arg)
{
	char		**nenv;
	char		**narg;
	char		*cdenv[3];
	char		**tmp;
	int			ret;

	if (!*env)
		return (RET_OK);
	try_m((nenv = ft_strtabdup(env)));
	try_m((narg = (char **)ft_memalloc(sizeof(char *) * 4)));
	init_cdenv(&cdenv[0], env);
	if (!arg[1])
		ret = setenv_cd(narg, cdenv[0], cdenv[2]);
	else if (ft_strequ(arg[1], "-") && !arg[2])
		ret = setenv_cd(narg, cdenv[1], cdenv[2]);
	else
		ret = change_dir(arg[1], narg, &cdenv[0]);
	try_m((narg[0] = ft_strdup("setenv")));
	var_set_line(&nenv, narg[1]);
	var_set_line(&nenv, narg[2]);
	tmp = data->env;
	try_m((data->env = ft_strtabdup(nenv)));
	free_cd_tabs(tmp, nenv, narg);
	return (ret);
}
