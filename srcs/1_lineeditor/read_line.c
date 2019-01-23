/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:20:58 by pespalie          #+#    #+#             */
/*   Updated: 2019/01/23 23:28:21 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	loop_enter(t_edl *edl, t_hist *hist)
{
	while (edl->index < (int)ft_strlen(edl->line))
		mouve_right(edl);
	edl->multiline = get_cursor_line(edl, edl->index, edl->line);
	ft_enter(edl);
	ft_putstr_fd("\n", 1);
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
	signal(SIGINT, signal_handler);
	display_prompt(&data->edl);
	while ((key = 0) || (data->eof == 0
				&& (read(STDIN_FILENO, &key, sizeof(key))) != 0))
	{
		if (key == ENTER)
		{
			loop_enter(&data->edl, &data->hist);
			break ;
		}
		else if (printable(key) == 0)
			print_line(data, key);
		else
			data->edl.line = ft_termcaps(&data->edl, key, &data->hist);
	}
	reset_term(data);
	add_line_to_command(data);
	signal(SIGINT, SIG_IGN);
}
