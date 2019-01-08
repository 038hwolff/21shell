/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:16:54 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/08 13:56:14 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	rewrite_line(t_edl *edl, char *line)
{
	int				i;

	i = 0;
	while (i < (int)ft_strlen(line))
	{
		if (edl->light[i] == 0)
			write(1, &line[i], 1);
		else if (edl->light[i] == 1)
		{
			ft_putstr_fd(tgetstr("so", NULL), 1);
			write(1, &line[i], 1);
			ft_putstr_fd(tgetstr("se", NULL), 1);
		}
		i++;
	}
}

void	erase_right(t_edl *edl)
{
	if (edl->light[edl->index] == 1)
	{
		edl->light[edl->index] = 0;
		edl->c_light--;
	}
	edl->index++;
	if ((edl->index + 2) % edl->col == 0)
		ft_putstr_fd(tgetstr("do", NULL), 1);
	else
		ft_putstr_fd(tgetstr("nd", NULL), 1);
}

void	select_letter(unsigned long key, t_edl *edl, char *line)
{
	if (edl->index >= 0 && edl->index <= (int)ft_strlen(line))
	{
		if (edl->light[edl->index] == 0)
		{
			edl->light[edl->index] = 1;
			edl->c_light++;
		}
		if (key == LEFT && edl->index - 1 >= 0)
		{
			edl->index--;
			ft_putstr_fd(tgetstr("le", NULL), 1);
			if (edl->light[edl->index] == 0)
			{
				edl->light[edl->index] = 1;
				edl->c_light++;
			}
		}
		if (key == RIGHT && edl->index < (int)ft_strlen(line))
			erase_right(edl);
	}
}

void	clear_space(t_edl *edl, char *line)
{
	size_t			len;
	int				i;
	size_t			j;

	i = -1;
	len = ft_strlen(line);
	while (++i < edl->multiline)
		ft_putstr_fd(tgoto(tgetstr("up", NULL), 0, 0), 1);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 0), 1);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	j = -1;
	while (++j <= (len_line(edl) + len))
		write(1, "\b", 1);
}

void	select_mode(t_edl *edl, unsigned long key, char *line)
{
	unsigned long	key_2;
	int				i;
	t_data			*data;

	data = get_data();
	while (key == SELECT)
	{
		key_2 = 0;
		read(STDIN_FILENO, &key_2, 10);
		if (key_2 == UP_FN)
			prev_word(edl, edl->line);
		if (key_2 == DOWN_FN)
			next_word(edl, edl->line, ft_strlen(edl->line));
		if (key_2 == SELECT)
			break ;
		select_letter(key_2, edl, line);
		clear_space(edl, line);
		display_prompt(data->prompt);
		rewrite_line(edl, line);
		edl->multiline = get_cursor_line(edl, edl->index, line);
		i = (int)ft_strlen(line);
		while (--i >= edl->index)
			ft_putstr_fd(tgetstr("le", NULL), 1);
	}
}
