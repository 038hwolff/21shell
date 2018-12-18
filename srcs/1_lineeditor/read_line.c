/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2018/10/30 19:47:44 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 10:37:14 by hwolff           ###   ########.fr       */
=======
/*   Created: 2018/12/18 10:20:58 by pespalie          #+#    #+#             */
/*   Updated: 2018/12/18 11:26:29 by pespalie         ###   ########.fr       */
>>>>>>> a5ce89813489e66478e7716f1427bd2d201f0418
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

int		printable(unsigned long key)
{
	if (key == TABU || key == CTRLD || (key > 31 && key < 128
		&& key != DOWN_FN && key != UP_FN && key != LEFT && key != RIGHT
		&& key != HOME && key != END && key != UP && key != DOWN
		&& key != LINE_UP && key != LINE_DOWN && key != COPY && key != PASTE
		&& key != CUT && key != SELECT))
		return (0);
	return (1);
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
			print_line(&data->edl, &data->edl.line, key);
		else
			data->edl.line = ft_termcaps(&data->edl, data->edl.line, key,
					&data->hist);
		key = 0;
	}
	reset_term(data);
}
