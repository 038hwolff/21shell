/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:54:17 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/14 20:59:03 by hben-yah         ###   ########.fr       */
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

	if (!line)
		return (0);
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
	int		decal;
	int		i;
	int 	keylen;

	if (!vars || !*vars || !key)
		return ;
	keylen = ft_strlen(key);
	decal = 0;
	i = 0;
	while ((*vars)[i + decal])
	{
		if (ft_strnequ((*vars)[i], key, keylen) && (*vars)[i][keylen] == '=')
		{
			ft_strdel(&(*vars)[i]);
			++decal;
		}
		else
		{
			(*vars)[i] = (*vars)[i + decal];
			++i;
		}
	}
	(*vars)[i] = NULL;
}
