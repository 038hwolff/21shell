/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unsetenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:36:43 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 16:31:05 by hwolff           ###   ########.fr       */
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

int		b_unsetenv(t_data *data)
{
	char	*tmp;
	int		i;
	int		j;

	i = 1;
	while (data->args[i])
	{
		j = 0;
		if (!(tmp = ft_strjoin(data->args[i], "=")))
			return (0);
		while (data->env[j])
		{
			if ((ft_strncmp(data->env[j], tmp, ft_strlen(tmp))) == 0)
				ft_rmvline(j, data);
			j++;
		}
		ft_strdel(&tmp);
		i++;
	}
	return (1);
}
