/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 21:17:05 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/16 19:01:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*complete_word(t_data *data)
{
	char	*ret;
	char	*end;
	char	*cpy;

	if (!data->edl.line || (data->edl.index > 0
		&& data->edl.line[data->edl.index - 1] == ' '))
		return (data->edl.line);
	try_m((ret = ft_strsub(data->edl.line, 0, data->edl.index)));
	exp_tilde(&ret, data);
	end = completion(data, ret);
	cpy = end;
	ft_strdel(&ret);
	if (end)
	{
		while (*end && *end != '=')
		{
			data->edl.line = insert_char(*(end++), &data->edl);
			++data->edl.index;
		}
		ft_strdel(&cpy);
	}
	return (data->edl.line);
}
