/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:45:59 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/08 21:37:09 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_hist	*setup_hist(t_hist *hist)
{
	try_m(hist->list = (char **)ft_memalloc(sizeof(char *) * 2));
	hist->h_count = 0;
	hist->h_current = 0;
	try_m(hist->copy = ft_strnew(0));
	return (hist);
}

t_edl	*setup_edl(t_edl *edl)
{
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	if (edl->line)
		ft_strdel(&edl->line);
	try_m(edl->line = ft_strnew(0));
	edl->index = 0;
	edl->col = ws.ws_col;
	edl->multiline = 0;
	return (edl);
}
