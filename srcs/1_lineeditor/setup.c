/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:45:59 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 20:08:27 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		prompt_len(void)
{
	int		i;
	t_data	*data;

	data = get_data();
	if (data->prompt_len)
		i = data->prompt_len;
	else
		i = 2;
	return (i);
}

int		len_line(t_edl *edl)
{
	int		i;
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
	edl->multiline = edl->index / edl->col;
	return (edl);
}
