/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:17:59 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/13 18:18:03 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

t_env	*save_env(t_env *new_env)
{
	static t_env	*stored_env = NULL;

	if (new_env)
		stored_env = new_env;
	return (stored_env);
}

void		wash_screen(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->height)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, i), 2);
		ft_putstr_fd(tgetstr("ce", NULL), 2);
		i++;
	}
}

void		s_window(t_env *env)
{
	struct winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	env->width = window.ws_col;
	env->height = window.ws_row;
}

void		refresh_screen(int signum)
{
	t_env 		*env;
	
	(void)signum;
	env = save_env(NULL);
	s_window(env);
	wash_screen(env);
}
