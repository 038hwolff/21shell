/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:23:42 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/15 14:42:21 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char *get_var(char *key)
{
	t_var *vars;

	vars = get_data()->loc;
	while ((*vars).key)
	{
		if (ft_strequ((*vars).key, key))
			return ((*vars).val);
		++vars;
	}
	return (NULL);
}

t_var	*newvartab(char **table)
{
	t_var	*new;
	t_var	*dnew;
	char		**keyval;
	size_t		len;

	len = (table ? ft_strtablen(table) : 0);
	if (!(new = (t_var *)ft_memalloc(sizeof(t_var) * (len + 1))))
		return (NULL);
	if (!len)
		return (new);
	dnew = new;
	while (*table)
	{
		if(!(keyval = ft_strsplit(*(table++), '='))
			|| !keyval[0] || !keyval[1])
			return (NULL);
		dnew->key = keyval[0];
		(dnew++)->val = keyval[1];
	}
	dnew = NULL;
	return (new);
}
