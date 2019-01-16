/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:04:22 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/16 17:08:14 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** FN + up arrow
*/

void	prev_word(t_edl *edl, char *line)
{
	if (edl->index - 1 >= 0)
	{
		if (!ft_isspace_wnt(line[edl->index - 1]))
		{
			while (edl->index - 1 >= 0 && !ft_isspace_wnt(line[edl->index - 1]))
				mouve_left(edl);
		}
		else
		{
			while (edl->index - 1 >= 0 && ft_isspace_wnt(line[edl->index - 1]))
				mouve_left(edl);
			while (edl->index - 1 >= 0 && !ft_isspace_wnt(line[edl->index - 1]))
				mouve_left(edl);
		}
	}
}

/*
** FN + down arrow
*/

void	next_word(t_edl *edl, char *line, size_t len)
{
	if (edl->index < (int)len)
	{
		if (line[edl->index + 1] && !ft_isspace_wnt(line[edl->index + 1]))
		{
			while (line[edl->index + 1] && !ft_isspace_wnt(line[edl->index + 1]))
				mouve_right(edl);
		}
		else if (!line[edl->index + 1])
				mouve_right(edl);
		else
		{
			while (line[edl->index + 1] && ft_isspace_wnt(line[edl->index + 1]))
				mouve_right(edl);
			while (line[edl->index + 1] && !ft_isspace_wnt(line[edl->index + 1]))
				mouve_right(edl);
		}
	}
}

/*
** "vs" = standout cursor
** "le" = String to move the cursor left one column.
*/

int		get_current_line_len(t_edl *edl, int i)
{
	char	*s;
	int		ncol;
	int		j;
	int		reset;

	s = edl->line;
	ncol = edl->prompt_len;
	j = 0;
	reset = 0;
	while (j <= i && s[j])
	{
		if (reset)
		{
			ncol = 0;
			reset = 0;
		}
		++ncol;
		if (s[j] == '\n' || ncol == edl->col)
			reset = 1;
		++j;
	}
	return (ncol);
}

void	mouve_left(t_edl *edl)
{
	int i;

	if (edl->index < 1)
		return ;
	ft_putstr_fd(tgetstr("vs", NULL), 1);
	--edl->index;
	if (edl->multiline > 0
		&& ((i = get_current_line_len(edl, edl->index)) == edl->col
			|| edl->line[edl->index] == '\n'))
	{
		//ft_printf("--%d--", i);
		--edl->multiline;
		ft_putstr_fd(tgetstr("up", NULL), 1);
		while (--i)
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
	int i;

	if (edl->index > (int)ft_strlen(edl->line))
		return ;
	ft_putstr_fd(tgetstr("vs", NULL), 1);
	if ((i = get_current_line_len(edl, edl->index)) == edl->col
		|| edl->line[edl->index] == '\n')
	{
		ft_putstr_fd(tgetstr("do", NULL), 1);
		++edl->multiline;
	}
	else
		ft_putstr_fd(tgetstr("nd", NULL), 1);
	ft_putstr_fd(tgetstr("ve", NULL), 1);
	++edl->index;
}
