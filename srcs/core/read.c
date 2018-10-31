/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:27:02 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 15:38:15 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		add_buff_to_entry(t_data *data, char *buff)
{
	char	*tmp;

	if (data->entry)
	{
		tmp = data->entry;
		data->entry = ft_strjoin(data->entry, buff);
		free(tmp);
	}
	else
		data->entry = ft_strdup(buff);
	if (!data->entry)
		return (0);
	return (1);
}

int				read_entry(t_data *data)
{
	int		z;
	int		tot;
	char	buff[BUFF_SIZE + 1];

	tot = 0;
	while ((z = read(0, buff, BUFF_SIZE)) >= 0)
	{
		buff[z] = 0;
		if (g_reset_entry)
		{
			g_reset_entry = 0;
			ft_strdel(&data->entry);
			tot = 0;
		}
		tot += z;
		if (!add_buff_to_entry(data, buff))
			return (0);
		if (is_valid_entry(data, z, tot))
			break ;
	}
	if (z == -1)
		exit(EXIT_FAILURE);
	data->childpid = 0;
	return (tot);
}
