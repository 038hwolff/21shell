/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:45:59 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/15 13:57:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	len_line(t_edl *edl)
{
	int	i;
	t_data	*data;

	data = get_data();
	if (data->prompt != NULL)
		i = ft_strlen(edl->line) + data->prompt_len;
	else
		i = ft_strlen(edl->line) + 2;
	return (i);
}

t_hist	*setup_hist(t_hist *hist)
{
	try_m(hist->list = (char **)ft_memalloc(sizeof(char *)));
	hist->h_count = 0;
	hist->h_current = 0;
	try_m(hist->copy = ft_strnew(0));
	return (hist);
}

t_edl	*setup_edl(t_edl *edl)
{
	struct winsize ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	try_m(edl->line = ft_strnew(0));
	edl->index = 0;
	edl->col = ws.ws_col;
	edl->multiline = edl->index / edl->col;
	return (edl);
}
