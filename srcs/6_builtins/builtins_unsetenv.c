/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unsetenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:36:43 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/15 22:23:39 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_rmvline(int j, t_data *data)
{
	ft_strdel(data->env + j);
	while (data->env[j + 1])
	{
		data->env[j] = data->env[j + 1];
		data->env[j + 1] = NULL;
		j++;
	}
}

int		b_unsetenv(t_data *data, char **arg)
{
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	while (arg[i])
	{
		j = 0;
		try_m((tmp = ft_strjoin(arg[i], "=")));
		while (data->env[j])
		{
			if ((ft_strnequ(data->env[j], tmp, ft_strlen(tmp))))
				ft_rmvline(j, data);
			j++;
		}
		ft_strdel(&tmp);
		i++;
	}
	return (1);
}
