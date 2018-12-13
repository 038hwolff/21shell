/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:40:28 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/05 11:04:12 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	ft_enter(char **line, t_edl *edl)
{
	char	*tmp;

	if (ft_strcmp(*line, "exit") == 0)
		exit (1);
	tmp = ft_strjoin(*line, "\n");
	free(*line);
	//*line = ft_strdup(tmp);
	//free(tmp);
	*line = tmp;
/*	if ((z = read_entry(&data)) > 0)
	{
		global_parse(&data);
		ft_strdel(&(data.entry));
	}*/
	edl->index = 0;
	return (0);
}
