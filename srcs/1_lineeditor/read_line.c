/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:20:58 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/08 14:00:38 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	loop_enter(t_edl *edl, char **line, t_hist *hist)
{
	if (ft_strcmp(*line, "\0") != 0)
	{
		while (edl->index < (int)ft_strlen(*line))
			mouve_right(edl);
		edl->multiline = get_cursor_line(edl, edl->index, edl->line);
		ft_enter(&(*line), edl);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		ft_putstr_fd("\n", 1);
		ft_strdel(line);
		try_m(*line = ft_strnew(0));
	}
	hist->h_current = 0;
}

int		printable(unsigned long key)
{
	if (key == TABU || key == CTRLD
		|| (((key > 31 && key < 128) || key == DELETE)
		&& key != DOWN_FN && key != UP_FN && key != LEFT && key != RIGHT
		&& key != HOME && key != END && key != UP && key != DOWN
		&& key != LINE_UP && key != LINE_DOWN && key != COPY && key != PASTE
		&& key != CUT && key != SELECT))
		return (0);
	return (1);
}

void	add_line_to_command(t_data *data)
{
	char *tmp;

	if (!data->command)
		try_m(data->command = ft_strdup(data->edl.line));
	else
	{
		try_m(tmp = ft_strjoin(data->command, data->edl.line));
		ft_strdel(&data->command);
		data->command = tmp;
	}
}

void	read_line(void)
{
	unsigned long	key;
	t_data			*data;

	data = get_data();
	init_term(data);
	setup_edl(&data->edl);
	signal_list();
	display_prompt(data->prompt);
	key = 0;
	while ((read(STDIN_FILENO, &key, 10)) != 0)
	{
		if (key == ENTER)
		{
			loop_enter(&data->edl, &data->edl.line, &data->hist);
			break ;
		}
		else if (printable(key) == 0)
			print_line(data, &data->edl.line, key);
		else
			data->edl.line = ft_termcaps(&data->edl, data->edl.line, key,
					&data->hist);
		key = 0;
	}
	reset_term(data);
	add_line_to_command(data);
}
