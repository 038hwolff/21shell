/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:53:55 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/29 18:26:29 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_eof(t_data *data)
{
	return (data->eof != 0
		&& !(data->shell_exit = 0)
		&& !(data->eof = 0));
}

int		check_if_sigint(t_data *data, char **line)
{
	if (line && *line
		&& data->sigint == 1)
	{
		ft_strdel(&data->edl.line);
		try_m(data->edl.line = ft_strdup(*line));
		ft_strdel(line);
		return (1);
	}
	return (0);
}

int		check_cancel(t_data *data, char **line)
{
	if (check_if_sigint(data, line))
		return (1);
	if (check_eof(data))
	{
		eof_exception(data->subcmd);
		ft_strdel(line);
		return (1);
	}
	return (0);
}
