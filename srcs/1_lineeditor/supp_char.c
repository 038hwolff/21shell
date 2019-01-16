/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:24:15 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/16 19:03:29 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*supp_char(t_edl *edl)
{
	char	*ret;
	int		len;
	int		i;

	if (edl->index == 0)
		return (edl->line);
	len = ft_strlen(edl->line);
	len < 2 ? len = 2 : 0;
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
		i++;
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
			if (--iline == 0)
				i += edl->prompt_len;
			while (i--)
				ft_putstr_fd(tgetstr("nd", NULL), 1);
		}
		else
			ft_putstr_fd(tgetstr("le", NULL), 1);
	}
	ft_putstr_fd(tgetstr("ve", NULL), 1);
}
