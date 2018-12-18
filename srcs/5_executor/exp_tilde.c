/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:54:47 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 08:54:48 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			exp_tilde(char **str, t_data *data)
{
	char		*tmp;
	char		*home;

	if ((*str)[0] == '~' && ((*str)[1] == '/' || !(*str)[1]))
	{
		if ((home = env_get(data->env, "HOME")))
		{
			tmp = *str;
			(*str) = ft_3strjoinfree(home, 0, &tmp[1], 0);
			free(tmp);
		}
	}
	return (1);
}
