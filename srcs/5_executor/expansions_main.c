/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:49:16 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/15 09:49:39 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
/*
int		manage_rest(t_data *data, char **res, int *i)
{
	char	*tmp2;
	char	*tmp;

	tmp = *res;
	if (!(tmp2 = ft_strsub(data->entry, *i, 1)) ||
		!(*res = ft_strjoin(*res, tmp2)))
		return (0);
	free(tmp);
	free(tmp2);
	return (1);
}

int		expansions(t_data *data)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 0;
	if (!(res = ft_strdup("")))
		return (0);
	while (data->entry[i])
	{
		if (data->entry[i] == '~')
			go_home(data, &res);
		else if (data->entry[i] == '$')
			manage_dollar(data, &res, &i);
		else if (data->entry[i] == '\\')
			manage_backslash(data, &res, &i);
		else
			manage_rest(data, &res, &i);
		i++;
	}
	tmp = data->entry;
	data->entry = res;
	free(tmp);
	return (1);
}*/
