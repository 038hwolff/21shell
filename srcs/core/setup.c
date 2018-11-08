/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:45:59 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 19:49:33 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_var	*setup_var(t_var *var)
{
	var = (t_var*)ft_memalloc(sizeof(t_var));
	var->hist = (char **)ft_memalloc(sizeof(char *));
	var->line = ft_strdup("\0");
	var->multiline = 0;
	var->index = 0;
	var->h_count = 0;
	var->h_current = 0;
	return (var);
}

void	setup_term(t_env *env)
{	
	char	*term_name;
	char	buf[1024];

	if (!(term_name = getenv("TERM")))
	{
		ft_putstr("Error getting TERM name");
		exit(1);
	}
	if (tcgetattr(0, &env->term) == -1)
	{
		ft_putstr("Error: not a terminal");
		exit (1);
	}
	env->term.c_lflag &= ~(ICANON | ECHO);
	env->term.c_cc[VMIN] = 1;
	env->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &env->term) == -1)
	{
		ft_putstr("Error: termios");
		exit (1);
	}
	if (tgetent(buf, getenv("TERM")) <= 0)
	{
		ft_putstr("Error: could not access the termcaps database");
		exit (1);
	}
	ft_putstr_fd(tgetstr("ti", NULL), 2);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
}

void	setup_env(int ac, char **av, t_env *env)
{
	env->words = av + 1;
	env->word_count = ac - 1;
	env->current_word = 0;
	setup_term(env);
}
