/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_high.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:51:35 by pespalie          #+#    #+#             */
/*   Updated: 2018/12/18 08:52:01 by pespalie         ###   ########.fr       */
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
	try_m(hist->copy = (char *)ft_memalloc(j * sizeof(char)));
	hist->copy[j] = '\0';
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
	try_m(new_line = (char *)ft_memalloc((ft_strlen(line) -
					ft_strlen(hist->copy)) * sizeof(char)));
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
	free(line);
	return (new_line);
}
