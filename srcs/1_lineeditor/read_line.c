/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:47:44 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/17 18:55:53 by hben-yah         ###   ########.fr       */
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

void	read_line()
{
	unsigned long	key;
	t_data		*data;

	data = get_data();

	init_term(data);
	setup_edl(&data->edl);
	display_prompt(data->prompt);
	while (key = 0, (read(STDIN_FILENO, &key, 10)) != 0)
	{
		if (key == ENTER)
		{
			loop_enter(&data->edl, &data->edl.line, &data->hist);
			break ;
		}
		else if (key == TABU || key == CTRLD || (key > 31 && key < 128
				&& key != DOWN_FN && key != UP_FN 
				&& key != LEFT && key != RIGHT && key != HOME
				&& key != END && key != UP && key !=DOWN
				&& key != LINE_UP && key != LINE_DOWN && key != COPY
				&& key != PASTE && key != CUT && key != SELECT))
			print_line(&data->edl, &data->edl.line, key);
		else
			data->edl.line = ft_termcaps(&data->edl, data->edl.line, key, &data->hist);
	}
	reset_term(data);
}

