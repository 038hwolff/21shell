/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:55:05 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 08:55:06 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**sh_env_get_ref(char **arr, char *key)
{
	int	klen;
	int	i;

	if (!arr)
		return (0);
	klen = ft_strlen(key);
	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			if (!ft_strncmp(arr[i], key, klen) && arr[i][klen] == '=')
				return (&arr[i]);
			i++;
		}
	}
	return (0);
}

char	*env_get(char **arr, char *key)
{
	int	klen;

	if (!arr || !key)
		return (0);
	klen = ft_strlen(key);
	while (*arr)
	{
		if (!ft_strncmp(*arr, key, klen) && (*arr)[klen] == '=')
			return (ft_strchr(*arr, '=') + 1);
		arr++;
	}
	return (0);
}
