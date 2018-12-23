/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:54:47 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/23 15:18:52 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			exp_tilde(char **str, t_data *data)
{
	char		*tmp;
	char		*home;

	if ((*str)[0] == '~' && ((*str)[1] == '/' || !(*str)[1]))
	{
		if ((home = var_get_val(data->env, "HOME")))
		{
			tmp = *str;
			(*str) = ft_3strjoinfree(home, 0, &tmp[1], 0);
			free(tmp);
		}
	}
	return (1);
}
