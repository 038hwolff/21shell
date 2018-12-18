/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:04:22 by pespalie          #+#    #+#             */
/*   Updated: 2018/12/18 09:05:08 by pespalie         ###   ########.fr       */
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

void	mouve_left(t_edl *edl)
{
	ft_putstr_fd(tgetstr("vs", NULL), 1);
	edl->index--;
	ft_putstr_fd(tgetstr("le", NULL), 1);
	if (((edl->index + 2) % edl->col) == 0 && edl->multiline)
		edl->multiline--;
	ft_putstr_fd(tgetstr("ve", NULL), 1);
}

/*
** "nd" = String to move the cursor right one column.
** "do" = String of commands to move the cursor vertically down one line
*/

void	mouve_right(t_edl *edl)
{
	t_data	*data;
	int		p_len;

	data = get_data();
	ft_putstr_fd(tgetstr("vs", NULL), 1);
	if (data->prompt != NULL)
		p_len = data->prompt_len;
	else
		p_len = 2;
	edl->index++;
	if ((edl->index + p_len) % edl->col == 0)
	{
		ft_putstr_fd(tgetstr("do", NULL), 1);
		edl->multiline++;
	}
	else
		ft_putstr_fd(tgetstr("nd", NULL), 1);
	ft_putstr_fd(tgetstr("ve", NULL), 1);
}
