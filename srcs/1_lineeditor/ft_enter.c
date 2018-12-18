/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:40:28 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 08:54:53 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_enter(char **line, t_edl *edl)
{
	char	*tmp;

	try_m(tmp = ft_strjoin(*line, "\n"));
	ft_strdel(line);
	try_m(*line = ft_strdup(tmp));
	ft_strdel(&tmp);
	edl->index = 0;
	return (0);
}
