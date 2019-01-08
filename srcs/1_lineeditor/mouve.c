/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:04:22 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/08 21:40:01 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** FN + up arrow
*/

void	prev_word(t_edl *edl, char *line)
{
	while (edl->index > 0 && !ft_isspace_wnt(line[edl->index]))
		mouve_left(edl);
	while (edl->index > 0 && ft_isspace_wnt(line[edl->index]))
		mouve_left(edl);
	while (edl->index > 0 && !ft_isspace_wnt(line[edl->index]))
		mouve_left(edl);
	if (edl->index > 0)
		mouve_right(edl);
}

/*
** FN + down arrow
*/

void	next_word(t_edl *edl, char *line, size_t len)
{
	while (edl->index < (int)len && !ft_isspace_wnt(line[edl->index]))
		mouve_right(edl);
	while (edl->index < (int)len && ft_isspace_wnt(line[edl->index]))
		mouve_right(edl);
}

/*
** "vs" = standout cursor
** "le" = String to move the cursor left one column.
*/

int		get_current_line_len(char *s, int index)
{
	int len;

	len = 0;
	while (*s && index--)
	{
		if (*s == '\n')
			len = 0;
		else
			++len;
		++s;
	}
	return (len);
}

void	mouve_left(t_edl *edl)
{
	int i;

	ft_putstr_fd(tgetstr("vs", NULL), 1);
	edl->index--;
	if (edl->multiline > 0
		&& (((edl->index + edl->prompt_len) % edl->col) == 0
			|| edl->line[edl->index] == '\n'))
	{
		edl->multiline--;
		ft_putstr_fd(tgetstr("up", NULL), 1);
		i = get_current_line_len(edl->line, edl->index);
		if (edl->multiline == 0)
			i += edl->prompt_len;
		while (i--)
			ft_putstr_fd(tgetstr("nd", NULL), 1);
	}
	else
		ft_putstr_fd(tgetstr("le", NULL), 1);
	ft_putstr_fd(tgetstr("ve", NULL), 1);
}

/*
** "nd" = String to move the cursor right one column.
** "do" = String of commands to move the cursor vertically down one line
*/

void	mouve_right(t_edl *edl)
{
	int		p_len;

	ft_putstr_fd(tgetstr("vs", NULL), 1);
	p_len = edl->prompt_len;
	edl->index++;
	if ((edl->index + p_len) % edl->col == 0
		|| edl->line[edl->index - 1] == '\n')
	{
		ft_putstr_fd(tgetstr("do", NULL), 1);
		edl->multiline++;
	}
	else
		ft_putstr_fd(tgetstr("nd", NULL), 1);
	ft_putstr_fd(tgetstr("ve", NULL), 1);
}
