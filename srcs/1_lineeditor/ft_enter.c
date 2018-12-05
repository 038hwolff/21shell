/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:40:28 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 17:44:39 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	ft_enter(char **line, t_edl *edl)
{
	char	*tmp;

	if (ft_strcmp(*line, "exit") == 0)
		exit (1);
	try_m(tmp = ft_strjoin(*line, "\n"));
	free(*line);
	try_m(*line = ft_strdup(tmp));
	free(tmp);
/*	if ((z = read_entry(&data)) > 0)
	{
		global_parse(&data);
		ft_strdel(&(data.entry));
	}*/
	edl->index = 0;
	return (0);
}
