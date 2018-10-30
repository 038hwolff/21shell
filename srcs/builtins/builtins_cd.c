/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:29:51 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 16:58:05 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void			cd_free(char **tmp, t_data *ndata)
{
	free_tab(&ndata->env);
	free_tab(&ndata->args);
	free_tab(&tmp);
}

static int		setenv_cd(t_data *ndata, char *env1, char *env2)
{
	if (env1)
	{
		chdir(env1);
		if (!(ndata->args[1] = ft_strjoin("PWD=", env1)))
			return (0);
	}
	if (env2)
	{
		if (!(ndata->args[2] = ft_strjoin("OLDPWD=", env2)))
			return (0);
	}
	return (1);
}

static int		change_dir(char *path, t_data *ndata, t_cdenv *cdenv)
{
	char	*buff;

	if (access(path, F_OK) != 0)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(path);
	}
	else if (access(path, X_OK) != 0)
	{
		ft_putstr("cd: permission denied: ");
		ft_putendl(path);
	}
	else
	{
		if (!(buff = ft_strnew(1024)))
			return (0);
		chdir(path);
		getcwd(buff, 1024);
		ndata->args[1] = ft_strjoin("PWD=", buff);
		ndata->args[2] = ft_strjoin("OLDPWD=", cdenv->pwd);
		free(buff);
		if (!ndata->args[1] || !ndata->args[2])
			return (0);
	}
	return (1);
}

static int		init_cdenv(t_cdenv *cdenv, t_data *data)
{
	int		i;

	i = 0;
	cdenv->home = NULL;
	cdenv->old = NULL;
	cdenv->pwd = NULL;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "HOME=", 5) == 0)
			cdenv->home = data->env[i] + 5;
		else if (ft_strncmp(data->env[i], "OLDPWD=", 7) == 0)
			cdenv->old = data->env[i] + 7;
		else if (ft_strncmp(data->env[i], "PWD=", 4) == 0)
			cdenv->pwd = data->env[i] + 4;
		i++;
	}
	return (1);
}

int				b_cd(t_data *data)
{
	t_data	ndata;
	t_cdenv	cdenv;
	char	**tmp;

	if (!data->env[0])
		return (0);
	if (!(ndata.env = ft_tabdup(data->env, 0)))
		return (0);
	if (!(ndata.args = ft_tabdup(NULL, 3)))
		return (0);
	init_cdenv(&cdenv, data);
	if (!data->args[1])
		setenv_cd(&ndata, cdenv.home, cdenv.pwd);
	else if ((ft_strcmp(data->args[1], "-") == 0) && !data->args[2])
		setenv_cd(&ndata, cdenv.old, cdenv.pwd);
	else
		change_dir(data->args[1], &ndata, &cdenv);
	trial((int)(ndata.args[0] = ft_strdup("setenv")));
	b_setenv(&ndata);
	tmp = data->env;
	if (!(data->env = ft_tabdup(ndata.env, 0)))
		return (0);
	cd_free(tmp, &ndata);
	return (1);
}
