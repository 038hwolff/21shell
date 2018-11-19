/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:47:44 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/19 16:55:07 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	displ_prompt(void)
{
	ft_putstr_fd(tgetstr("me", NULL), 2);
	ft_putstr_fd("$>", 2);
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
		ft_putstr_fd("\n", 2);
	}
	else
		ft_putstr_fd("\n", 2);
	displ_prompt();
	free(*line);
	var->h_current = 0;
	*line = ft_strdup("\0");
}

void	loop(void)
{
	char	buf[1000];
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	ft_bzero(buf, 1000);
	var = setup_var(var);
	while (1)
	{
	//	signal_handler(&restart);
		signal_handler(NULL);
		ft_bzero(buf, 1000);
		read(STDIN_FILENO, buf, 1000);
		if (ENTER)
			loop_enter(var, &var->line);
		else if (buf[0] != '\0' && !HAUT && !BAS && !GAUCHE && !DROITE)
			print_line(var, &var->line, buf);
		else
			var->line = ft_termcaps(var, var->line, buf);
	}
}
