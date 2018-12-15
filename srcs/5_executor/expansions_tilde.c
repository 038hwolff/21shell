/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_tilde.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:49:50 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/16 00:18:31 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		go_home(t_data *data, char **res)
{
	int		j;
	char	*tmp;

	j = 0;
	while (data->env[j] && (ft_strncmp(data->env[j], "HOME=", 5) != 0))
		j++;
	if (data->env[j])
	{
		tmp = *res;
		if (!(*res = ft_strjoin(*res, data->env[j] + 5)))
			return (0);
		free(tmp);
	}
	return (1);
}
