/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:33:34 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/16 19:42:21 by hben-yah         ###   ########.fr       */
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

void	line_moves(t_edl *edl, unsigned long key)
{
	int	i;
	int len;
	int nlen;
	int l;

	i = 0;
	l = edl->multiline;
	len = get_current_line_len(edl, edl->index);
	if (key == LINE_UP)
	{
		while (i++ < len)
			mouve_left(edl);
		mouve_left(edl);
		nlen = get_current_line_len(edl, edl->index);
		while (nlen-- > len)
			mouve_left(edl);
	}
	else if (key == LINE_DOWN)
	{
		while (l == edl->multiline && edl->line[edl->index])
			mouve_right(edl);
		nlen = 1;
		while (nlen++ < len && edl->line[edl->index])
			mouve_right(edl);
	}
}

/*
** SELECTION = fn + v
** COPY = fn + y
** PASTE = fn + p
*/

void	term_moves(unsigned long key, t_edl *edl, size_t len)
{
	if (key == LEFT || key == RIGHT || key == HOME || key == END)
		left_or_right(edl, key, len);
	if (key == UP_FN)
		prev_word(edl);
	if (key == DOWN_FN)
		next_word(edl, len);
	if (key == LINE_UP || key == LINE_DOWN)
		line_moves(edl, key);
}

char	*ft_termcaps(t_edl *edl, unsigned long key, t_hist *hist)
{
	size_t			len;
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	edl->col = ws.ws_col;
	len = ft_strlen(edl->line);
	if (key == UP)
		history_umove(edl, hist);
	if (key == DOWN)
		history_dmove(edl, hist);
	term_moves(key, edl, len);
	if (key == SELECT && ft_strcmp(edl->line, "\0") != 0)
		select_mode(edl, key);
	if (key == COPY && ft_strcmp(edl->line, "\0"))
		copy_high(edl, hist);
	if (key == CUT && ft_strcmp(edl->line, "\0"))
		edl->line = cut_high(edl, hist);
	if (key == PASTE && edl->c_light != 0)
		edl->line = paste_char(edl, hist);
	return (edl->line);
}
