/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:49:38 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/16 19:09:07 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*delete_char(int index, char *line, int len)
{
	int		i;
	char	*ret;

	i = 0;
	try_m(ret = (char *)ft_memalloc(len * sizeof(char)));
	while (i < index)
	{
		ret[i] = line[i];
		i++;
	}
	while (i < len - 1)
	{
		ret[i] = line[i + 1];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*control_d(t_data *data)
{
	char	*ret;
	size_t	len;

	ret = NULL;
	if (!*data->edl.line)
	{
		data->eof = 1;
		if (data->incomp_type == 0)
			exit_program(0);
		return (data->edl.line);
	}
	len = ft_strlen(data->edl.line);
	if (data->edl.index == (int)len)
		return (data->edl.line);
	ret = delete_char(data->edl.index, data->edl.line, len);
	ft_strdel(&data->edl.line);
	return (ret);
}
