/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:47:44 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/30 14:29:56 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	loop_enter(t_edl *edl, char **line, t_hist *hist)
{
	if (ft_strcmp(*line, "\0") != 0)
	{
		hist->list = add_history(*line, hist);
		while (edl->index < (int)ft_strlen(*line))
			mouve_right(edl);
		edl->multiline = len_line(edl) / edl->col;
		ft_enter(*line, edl);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		ft_putstr_fd("\n", 1);
		hist->h_current = 0;
		free(*line);
		*line = ft_strnew(0);
	}
}

void	read_line(void)
{
	unsigned long	key;
	t_data		*data;

	data = get_data();
	setup_edl(&data->edl);
	display_prompt();
	while (key = 0, (read(STDIN_FILENO, &key, 10)) != 0)
	{
		signal_handler(NULL);
		if (key == ENTER)
		{
			loop_enter(&data->edl, &data->edl.line, &data->hist);
			return ;
		}
		else if (key == TAB || (key > 31 && key < 128 && key != DOWN_FN && key != UP_FN 
				&& key != LEFT && key != RIGHT && key != HOME
				&& key != END && key != UP && key !=DOWN
				&& key != LINE_UP && key != LINE_DOWN))
			print_line(&data->edl, &data->edl.line, key);
		else
			data->edl.line = ft_termcaps(&data->edl, data->edl.line, key, &data->hist);
	}
}

