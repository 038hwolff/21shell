/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_high.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:51:35 by pespalie          #+#    #+#             */
/*   Updated: 2018/12/18 20:48:48 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

char	*stock_line(char *line, t_edl *edl, t_hist *hist)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(line);
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
			hist->copy[++j] = line[i];
	return (hist->copy);
}

/*
** CUT = alt + d
*/

char	*cut_high(t_edl *edl, t_hist *hist, char *line)
{
	char	*new_line;
	size_t	len;
	size_t	i;
	size_t	j;
	int		c;

	len = ft_strlen(line);
	hist->copy = stock_line(line, edl, hist);
	try_m(new_line = ft_strnew((ft_strlen(line) - ft_strlen(hist->copy))));
	i = -1;
	j = -1;
	while (++i < len)
		if (edl->light[i] == 0)
			new_line[++j] = line[i];
	edl->multiline = edl->index / edl->col;
	clear_line(edl, new_line);
	c = (int)ft_strlen(new_line);
	while (--c >= edl->index)
		ft_putstr_fd(tgetstr("le", NULL), 1);
	ft_strdel(&line);
	return (new_line);
}
