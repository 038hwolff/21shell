/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:49:38 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/11 19:07:14 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*delete_char(int **index, char *line, int len)
{
	int		i;
	char	*ret;

	i = 0;
	try_m(ret = (char *)ft_memalloc(len * sizeof(char)));
	while (i < **index)
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

char	*control_d(char *line, int *index)
{
	char	*ret;
	size_t	len;
	t_data	*data;

	ret = NULL;
	data = get_data();
	if (!*line)
	{
		data->eof = 1;
		if (data->incomp_type == 0)
			exit_program(0);
		return (line);
	}
	len = ft_strlen(line);
	if (*index == (int)len)
		return (line);
	ret = delete_char(&index, line, len);
	ft_strdel(&line);
	return (ret);
}
