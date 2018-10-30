/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_setenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:36:13 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 16:30:27 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	add_to_env(t_data *ndata, t_data *data, int i)
{
	char *key;
	char *value;

	key = ft_strsub(data->args[i], 0,
			ft_strchr(data->args[i], '=') - data->args[i] + 1);
	value = ft_strdup(ft_strchr(data->args[i], '=') + 1);
	trial(key && value);
	trial((int)(ft_setline(key, value, ndata)));
	ft_strdel(&key);
	ft_strdel(&value);
}

int		ft_setline(char *key, char *value, t_data *data)
{
	char	**ret;
	int		i;
	char	*end;

	i = 0;
	end = NULL;
	trial((int)(ret = ft_tabdup(data->env, 1)));
	while (ret[i])
	{
		if (ft_strncmp(key, ret[i], ft_strlen(key)) == 0)
		{
			check_key(ret, i, key, value);
			free_tab(&data->env);
			data->env = ret;
			return (1);
		}
		i++;
	}
	if (!(ret[i++] = ft_strjoin(key, value)))
		return (0);
	ret[i] = NULL;
	free_tab(&data->env);
	data->env = ret;
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

	if (!(tmp = ft_strjoin(key, value)))
		exit(EXIT_FAILURE);
	free(ret[i]);
	ret[i] = tmp;
	return (ret);
}

int		b_setenv(t_data *data)
{
	char	*key;
	char	*value;
	int		i;

	i = 1;
	while (data->args[i])
	{
		value = ft_strchr(data->args[i], '=') + 1;
		if ((long)value > 1)
		{
			if (!(key = ft_strsub(data->args[i], 0, value - data->args[i]))
				|| !(ft_setline(key, value, data)))
				return (0);
			ft_strdel(&key);
		}
		i++;
	}
	return (0);
}
