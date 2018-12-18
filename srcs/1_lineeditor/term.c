/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:33:34 by pespalie          #+#    #+#             */
/*   Updated: 2018/12/18 09:34:18 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** HOME = FN + left arrow
** END = FN + right arrow
*/

void	left_or_right(t_edl *edl, unsigned long key, size_t len)
{
	if (key == LEFT && edl->index > 0)
		mouve_left(edl);
	if (key == RIGHT && edl->index < (int)len)
		mouve_right(edl);
	if (key == HOME)
		while (edl->index > 0)
			mouve_left(edl);
	if (key == END)
	{
		while (edl->index < (int)len)
			mouve_right(edl);
	}
}

/*
** LINE_UP = maj + up arrow
** LINE_DOWN = maj + down arrow
*/

void	line_moves(t_edl *edl, char *line, unsigned long key)
{
	int	i;

	i = 0;
	if (key == LINE_UP && edl->multiline)
	{
		while (i < edl->col && edl->index > 0)
		{
			mouve_left(edl);
			i++;
		}
	}
	if (key == LINE_DOWN && (len_line(edl) / edl->col) > 0)
	{
		while (i < edl->col && edl->index < (int)ft_strlen(line))
		{
			mouve_right(edl);
			i++;
		}
	}
}

/*
** SELECTION = fn + v
** COPY = fn + y
** PASTE = fn + p
*/

void	term_moves(unsigned long key, t_edl *edl, size_t len, char *line)
{
	if (key == LEFT || key == RIGHT || key == HOME || key == END)
		left_or_right(edl, key, len);
	if (key == UP_FN)
		prev_word(edl, line);
	if (key == DOWN_FN)
		next_word(edl, line, len);
	if (key == LINE_UP || key == LINE_DOWN)
		line_moves(edl, line, key);
}

char	*ft_termcaps(t_edl *edl, char *line, unsigned long key, t_hist *hist)
{
	size_t			len;
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	edl->col = ws.ws_col;
	len = ft_strlen(line);
	if (key == UP)
		history_umove(edl, &line, hist);
	if (key == DOWN)
		history_dmove(edl, &line, hist);
	term_moves(key, edl, len, line);
	if (key == SELECT && ft_strcmp(line, "\0") != 0)
		select_mode(edl, key, line);
	if (key == COPY && ft_strcmp(line, "\0"))
		copy_high(edl, hist, line);
	if (key == CUT && ft_strcmp(line, "\0"))
		line = cut_high(edl, hist, line);
	if (key == PASTE && edl->c_light != 0)
		line = paste_char(edl, hist, line);
	return (line);
}
