/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_setenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:36:13 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/17 09:43:36 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	add_to_env(char **nenv, char **arg, int i)
{
	char *key;
	char *value;
	char *pequal;

	pequal = ft_strchr(arg[i], '=');
	try_m((key = ft_strsub(arg[i], 0,
			pequal - arg[i] + 1)));
	try_m((value = ft_strdup(pequal + 1)));
	ft_setline(key, value, &nenv);
	ft_strdel(&key);
	ft_strdel(&value);
}

int		ft_setline(char *key, char *value, char ***env)
{
	char	**ret;
	int		i;
	char	*end;

	i = 0;
	end = NULL;
	try_m((ret = ft_strtabdup(*env)));
	while (ret[i])
	{
		if (ft_strncmp(key, ret[i], ft_strlen(key)) == 0)
		{
			check_key(ret, i, key, value);
			free_tab(env);
			*env = ret;
			return (1);
		}
		i++;
	}
	try_m((ret[i++] = ft_strjoin(key, value)));
	ret[i] = NULL;
	free_tab(env);
	*env = ret;
	return (1);
}

char	**ft_tabdup(char **table, size_t z)
{
	char	**ret;
	int		i;

	i = 0;
	if (table)
		while (table[i])
			i++;
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (i + z + 1))))
		return (NULL);
	if (table)
	{
		i = 0;
		while (table[i])
		{
			if (!(ret[i] = ft_strdup(table[i])))
				return (NULL);
			i++;
		}
		ret[i] = NULL;
	}
	return (ret);
}

char	**check_key(char **ret, int i, char *key, char *value)
{
	char	*tmp;

	try_m((tmp = ft_strjoin(key, value)));
	free(ret[i]);
	ret[i] = tmp;
	return (ret);
}

int		b_setenv(char ***env, char **arg)
{
	char	*key;
	char	*value;
	int		i;

	i = 1;
	while (arg[i])
	{
		value = ft_strchr(arg[i], '=') + 1;
		if ((long)value > 1)
		{
			if (!(key = ft_strsub(arg[i], 0, value - arg[i]))
				|| !(ft_setline(key, value, env)))
				return (0);
			ft_strdel(&key);
		}
		i++;
	}
	return (0);
}
