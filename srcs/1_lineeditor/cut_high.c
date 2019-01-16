/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_high.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:51:35 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/16 19:22:22 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*stock_line(t_edl *edl, t_hist *hist)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(edl->line);
	i = -1;
	j = 0;
	while (++i < len)
		if (edl->light[i] == 1)
			j++;
	if (hist->copy)
		ft_strdel(&hist->copy);
	try_m(hist->copy = ft_strnew(j));
	i = -1;
	j = -1;
	while (++i < len)
		if (edl->light[i] == 1)
			hist->copy[++j] = edl->line[i];
	return (hist->copy);
}

/*
** CUT = alt + d
*/

char	*cut_high(t_edl *edl, t_hist *hist)
{
	char	*new_line;
	size_t	len[2];
	size_t	i;
	size_t	j;
	int		c;

	len[0] = ft_strlen(edl->line);
	hist->copy = stock_line(edl, hist);
	len[1] = ft_strlen(edl->line) - ft_strlen(hist->copy);
	try_m(new_line = ft_strnew(len[1]));
	i = -1;
	j = -1;
	while (++i < len[0])
		if (edl->light[i] == 0)
			new_line[++j] = edl->line[i];
	while (edl->index > (int)len[1])
		mouve_left(edl);
	edl->multiline = get_cursor_line(edl, edl->index, new_line);
	clear_line(edl, new_line);
	c = (int)ft_strlen(new_line);
	while (--c >= edl->index)
		ft_putstr_fd(tgetstr("le", NULL), 1);
	ft_strdel(&edl->line);
	return (new_line);
}
