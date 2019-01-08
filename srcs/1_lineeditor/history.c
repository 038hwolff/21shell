/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:55:14 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/08 21:47:25 by hben-yah         ###   ########.fr       */
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
		edl->linecpy = NULL;
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
