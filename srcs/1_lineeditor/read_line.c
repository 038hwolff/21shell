/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:47:44 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/21 17:50:53 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	display_prompt(void)
{
	ft_putstr_fd(tgetstr("me", NULL), 1);
	ft_putstr_fd("$>", 1);
	return ;
}

void	loop_enter(t_var *var, char **line)
{
	if (ft_strcmp(*line, "\0") != 0)
	{
		var->hist = add_history(var, *line);
		while (var->index < (int)ft_strlen(*line))
			mouve_right(var);
		var->multiline = len_line(var) / var->col;
		ft_enter(*line, var);
		ft_putstr_fd("\n", 1);
	}
	else
		ft_putstr_fd("\n", 1);
	display_prompt();
	var->h_current = 0;
	free(*line);
	*line = ft_strdup("\0");
}

void	read_line(void)
{
	unsigned long	key;
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	var = setup_var(var);
	while (key = 0, (read(STDIN_FILENO, &key, 10)) != 0)
	{
		signal_handler(NULL);
		if (key == ENTER)
			loop_enter(var, &var->line);
		else if (key != DOWN_FN && key != UP_FN && key != LEFT && key != RIGHT
				&& key != HOME && key != END && key != UP && key !=DOWN)
			print_line(var, &var->line, key);
		else
			var->line = ft_termcaps(var, var->line, key);
	}
}
