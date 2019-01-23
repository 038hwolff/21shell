/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:24:15 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/24 00:16:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*supp_char(t_edl *edl, unsigned long key)
{
	char	*ret;
	int		len;
	int		i;

	if (!(len = ft_strlen(edl->line)) || (key == SUPP && edl->index == 0)
		|| (key == DELETE && (!edl->line[edl->index] || !++edl->index)))
		return (edl->line);
	len = (len < 2 ? 2 : len);
	try_m(ret = ft_strnew(len));
	i = 0;
	while (i < edl->index - 1)
	{
		ret[i] = edl->line[i];
		++i;
	}
	while (i < len - 1)
	{
		ret[i] = edl->line[i + 1];
		++i;
	}
	ret[i] = '\0';
	--edl->index;
	if (edl->line)
		ft_strdel(&edl->line);
	return (ret);
}

void	move_cursor_to_index(t_edl *edl)
{
	int iline;
	int	len;
	int	i;

	ft_putstr_fd(tgetstr("vs", NULL), 1);
	len = ft_strlen(edl->line);
	iline = get_cursor_line(edl, len, edl->line);
	while (len-- > edl->index)
	{
		if (iline > 0
			&& (((edl->index + edl->prompt_len) % edl->col) == 0
				|| edl->line[len] == '\n'))
		{
			ft_putstr_fd(tgetstr("up", NULL), 1);
			i = get_current_line_len(edl, len) - 1;
			--iline;
			while (i--)
				ft_putstr_fd(tgetstr("nd", NULL), 1);
		}
		else
			ft_putstr_fd(tgetstr("le", NULL), 1);
	}
	ft_putstr_fd(tgetstr("ve", NULL), 1);
}

void	erase_line(t_data *data)
{
	int	c;

	c = -1;
	while (++c < data->edl.multiline)
		ft_putstr_fd(tgoto(tgetstr("up", NULL), 0, 0), 1);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 0), 1);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
}
