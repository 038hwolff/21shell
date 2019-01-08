/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:40:28 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/07 18:03:40 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_enter(char **line, t_edl *edl)
{
	char	*tmp;

	try_m(tmp = ft_strjoin(*line, "\n"));
	ft_strdel(line);
	*line = tmp;
	edl->index = 0;
	return (0);
}
