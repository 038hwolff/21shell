/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:43:23 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 08:39:54 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** interception de signaux pour ne rien faire
*/

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
