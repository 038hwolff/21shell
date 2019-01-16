/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:55:14 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/16 17:48:28 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	history_move(t_edl *edl, char **line, char *nline)
{
	int		i;

	i = edl->prompt_len;
	while (edl->index > 0)
		mouve_left(edl);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, i), 1);
	ft_putstr_fd(tgetstr("ce", NULL), 1);
	ft_putstr_fd(nline, 1);
	ft_strdel(line);
	try_m(*line = ft_strdup(nline));
	edl->index = ft_strlen(*line);
	edl->multiline = get_cursor_line(edl, edl->index, *line);
	if (edl->light)
		ft_memdel((void **)&edl->light);
	try_m(edl->light = (int *)ft_memalloc((edl->index + 1) * sizeof(int)));
}

void	history_dmove(t_edl *edl, char **line, t_hist *hist)
{
	int		j;
	char	*to_display;

	j = hist->h_current;
	if (hist->h_count == 0 || j == 0)
	{
		hist->h_current = 0;
		ft_putstr_fd(tgetstr("bl", NULL), 1);
		return ;
	}
	else if (j == hist->h_count)
	{
		to_display = edl->linecpy;
		hist->h_current = 0;
	}
	else
	{
		to_display = hist->list[j];
		hist->h_current = j + 1;
	}
	history_move(edl, line, to_display);
}

void	history_umove(t_edl *edl, char **line, t_hist *hist)
{
	int		j;

	if (hist->h_current == 0)
	{
		if (edl->linecpy)
			ft_strdel(&edl->linecpy);
		try_m(edl->linecpy = ft_strdup(*line));
		j = hist->h_count - 1;
	}
	else
		j = hist->h_current - 2;
	if (j < 0)
	{
		ft_putstr_fd(tgetstr("bl", NULL), 1);
		return ;
	}
	hist->h_current = j + 1;
	history_move(edl, line, hist->list[j]);
}

char	**ft_realloc(t_hist *hist, char *value)
{
	int		i;
	char	**new_env;

	try_m(new_env = (char **)ft_memalloc(sizeof(char *)
				* (hist->h_count + 2)));
	i = 0;
	while (i < hist->h_count)
	{
		try_m(new_env[i] = ft_strdup(hist->list[i]));
		++i;
	}
	try_m(new_env[i] = ft_strdup(value));
	ft_tabdel((void ***)&hist->list);
	return (new_env);
}

char	**add_history(char *value, t_hist *hist)
{
	if (hist->h_count > 0)
		try_m(ft_strtabrealloc(&hist->list, hist->h_count + 1));
	hist->list[hist->h_count] = value;
	++hist->h_count;
	return (hist->list);
}
