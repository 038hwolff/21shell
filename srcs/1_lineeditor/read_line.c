/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:47:44 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/22 22:26:16 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	loop_enter(t_edl *edl, char **line)
{
	if (ft_strcmp(*line, "\0") != 0)
	{
		edl->hist = add_history(edl, *line);
		while (edl->index < (int)ft_strlen(*line))
			mouve_right(edl);
		edl->multiline = len_line(edl) / edl->col;
		ft_enter(*line, edl);
		ft_putstr_fd("\n", 1);
	}
	else
	{
		ft_putstr_fd("\n", 1);
		//display_prompt();
		edl->h_current = 0;
		free(*line);
		*line = ft_strdup("\0");
	}
}

void	read_line(void)
{
	unsigned long	key;
	t_edl	*edl;

	//edl = (t_edl *)malloc(sizeof(t_edl));
	edl = setup_edl(&get_data()->edl);
	while (key = 0, (read(STDIN_FILENO, &key, 10)) != 0)
	{
		signal_handler(NULL);
		if (key == ENTER)
		{
			loop_enter(edl, &edl->line);
			return ;
		}
		else if (key == 9 || (key > 31 && key < 128 && key != DOWN_FN && key != UP_FN 
				&& key != LEFT && key != RIGHT && key != HOME
				&& key != END && key != UP && key !=DOWN))
			print_line(edl, &edl->line, key);
		else
			edl->line = ft_termcaps(edl, edl->line, key);
	}
}
