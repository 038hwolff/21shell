/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:40:28 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/17 19:14:54 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_enter(char **line, t_edl *edl)
{
	char	*tmp;

	//if (ft_strcmp(*line, "exit") == 0)
	//	exit_program(NULL);
	try_m(tmp = ft_strjoin(*line, "\n"));
	ft_strdel(line);
	try_m(*line = ft_strdup(tmp));
	ft_strdel(&tmp);
/*	if ((z = read_entry(&data)) > 0)
	{
		global_parse(&data);
		ft_strdel(&(data.entry));
	}*/
	edl->index = 0;
	return (0);
}
