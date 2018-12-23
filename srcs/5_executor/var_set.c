/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:54:17 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/23 18:31:12 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		var_set(char ***vars, char *key, char *value)
{
	char	**env;
	char	*new;

	if (!key || !value)
		return (0);
	ft_asprintf(&new, "%s%s%s", key, "=", value);
	if (!new)
		return (0);
	if ((env = var_get_ptr(*vars, key)))
	{
		free(*env);
		*env = new;
	}
	else if (!ft_strtab_add(vars, new))
	{
		free(new);
		return (0);
	}
	return (1);
}

int		var_set_line(char ***vars, char *line)
{
	char	*key;
	char	*value;
	int		ret;

	ret = 1;
	if (!(value = ft_strchr(line, '=')))
		return (0);
	try_m((key = ft_strsub(line, 0, value - line)));
	ret = var_set(vars, key, value + 1);
	ft_strdel(&key);
	return (ret);
}

void	var_unset(char ***vars, char *key)
{
	char	**env;
	int		decal;
	int		i;

	if (!(env = var_get_ptr(*vars, key)))
		return ;
	decal = 0;
	i = 0;
	while ((*vars)[i])
	{
		if ((*vars)[i] == *env)
		{
			free((*vars)[i]);
			++decal;
		}
		(*vars)[i] = (*vars)[i + decal];
		++i;
	}
}
