/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_paste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:49:43 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/08 13:53:12 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** COPY = alt + c
*/

void	copy_high(t_edl *edl, t_hist *hist, char *line)
{
	size_t	i;
	int		j;
	size_t	len;

	j = 0;
	i = -1;
	len = ft_strlen(line);
	while (++i < len)
		if (edl->light[i] == 1)
			j++;
	if (hist->copy)
		ft_strdel(&hist->copy);
	try_m(hist->copy = (char *)ft_memalloc(j * sizeof(char) + 1));
	j = -1;
	i = -1;
	while (++i < len)
		if (edl->light[i] == 1)
			hist->copy[++j] = line[i];
	hist->copy[++j] = '\0';
}

void	clear_line(t_edl *edl, char *n_line)
{
	int		i;
	t_data	*data;

	i = -1;
	data = get_data();
	while (++i < edl->multiline)
		ft_putstr_fd(tgoto(tgetstr("up", NULL), 0, 0), 1);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 0), 1);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	i = -1;
	while (++i < len_line(edl) + (int)ft_strlen(n_line))
		write(1, "\b", 1);
	display_prompt(data->prompt);
	ft_putstr_fd(n_line, 1);
}

char	*create_newline(t_edl *edl, char *line, t_hist *hist)
{
	int		i;
	int		j;
	int		l;
	char	*new_line;

	i = 0;
	j = 0;
	l = 0;
	try_m(new_line = ft_strnew(ft_strlen(line) + ft_strlen(hist->copy)));
	while (i < edl->index)
		new_line[i++] = line[l++];
	while (hist->copy[j])
		(new_line[i++] = hist->copy[j++]) && edl->index++;
	while (line[l])
		new_line[i++] = line[l++];
	new_line[i] = '\0';
	return (new_line);
}

/*
** PASTE = alt + p
*/

char	*paste_char(t_edl *edl, t_hist *hist, char *line)
{
	char	*new_line;
	int		i;

	new_line = NULL;
	new_line = create_newline(edl, line, hist);
	ft_putstr_fd(tgetstr("se", NULL), 1);
	clear_line(edl, new_line);
	i = ft_strlen(new_line);
	while (--i >= edl->index)
		ft_putstr_fd(tgetstr("le", NULL), 1);
	edl->multiline = get_cursor_line(edl, edl->index, new_line);
	if (edl->light)
		ft_memdel((void**)&edl->light);
	try_m(edl->light = (int *)ft_memalloc((ft_strlen(new_line) + 1)
		* sizeof(int)));
	ft_strdel(&line);
	return (new_line);
}
