/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 21:17:05 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/10 19:59:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*complete_word(t_data *data, char *line)
{
	char	*ret;
	char	*end;
	char	*cpy;

	if (!line || (data->edl.index > 0 && line[data->edl.index - 1] == ' '))
		return (line);
	try_m((ret = ft_strsub(line, 0, data->edl.index)));
	exp_tilde(&ret, data);
	end = completion(data, ret);
	cpy = end;
	ft_strdel(&ret);
	if (end)
	{
		while (*end && *end != '=')
		{
			line = insert_char(line, *(end++), &data->edl.index, &data->edl);
			++data->edl.index;
		}
		ft_strdel(&cpy);
	}
	return (line);
}
