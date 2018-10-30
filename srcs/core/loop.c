/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:47:44 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 19:49:11 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	display_prompt(void)
{
	ft_putstr_fd(tgetstr("me", NULL), 2);
	ft_putstr_fd("$> ", 2);
	return ;
}

void	loop_enter(t_var *var, char **line)
{
	(void)var;

	if (ft_strcmp(*line, "\0") != 0)
	{
		var->history[var->h_count] = ft_strdup(*line);
		var->h_count++;
		while (var->index < (int)ft_strlen(*line))
			mouve_right(var);
		ft_enter(*line, var);
		ft_putstr_fd("\n", 2);
	}
	else
		ft_putstr_fd("\n", 2);
	display_prompt();
	free(*line);
	*line = ft_strdup("\0");
}

void	loop(t_env *env)
{
	(void)env;
	char	buf[1000];
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	ft_bzero(buf, 1000);
	var = setup_var(var);
	while (1)
	{
		ft_bzero(buf, 1000);
		read(STDIN_FILENO, buf, 1000);
		if (ENTER)
			loop_enter(var, &var->line);
		else if (buf[0] != '\0' && !HAUT && !BAS && !GAUCHE && !DROITE)
			print_line(var, &var->line, buf);
	}
}
