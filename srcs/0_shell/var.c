/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:23:42 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/15 14:15:55 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			*get_variable(char *key)
{
	t_variable *vars;

	vars = get_data()->loc;
	while ((*vars).key)
	{
		if (ft_strequ((*vars).key, key))
			return ((*vars).val);
		++vars;
	}
	return (NULL);
}

t_variable		*newvartab(char **table)
{
	t_variable	*new;
	t_variable	*dnew;
	char		**keyval;
	size_t		len;

	len = (table ? ft_strtablen(table) : 0);
	if (!(new = (t_variable *)ft_memalloc(sizeof(t_variable) * (len + 1))))
		return (NULL);
	if (!len)
		return (new);
	dnew = new;
	while (*table)
	{
		if (!(keyval = ft_strsplit(*(table++), '='))
			|| !keyval[0] || !keyval[1])
			return (NULL);
		dnew->key = keyval[0];
		(dnew++)->val = keyval[1];
	}
	dnew = NULL;
	return (new);
}
