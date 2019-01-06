/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:55:05 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/06 12:54:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**var_get_ptr(char **arr, char *key)
{
	int	keylen;
	int	i;

	if (!arr || !key)
		return (0);
	keylen = ft_strlen(key);
	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			if (ft_strnequ(arr[i], key, keylen) && arr[i][keylen] == '=')
				return (&arr[i]);
			i++;
		}
	}
	return (0);
}

char	*var_get_val(char **vars, char *key)
{
	int	keylen;

	if (!vars || !key)
		return (0);
	keylen = ft_strlen(key);
	while (*vars)
	{
		if (ft_strnequ(*vars, key, keylen) && (*vars)[keylen] == '=')
			return (ft_strchr(*vars, '=') + 1);
		++vars;
	}
	return (0);
}
