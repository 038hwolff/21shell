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

int	len_line(t_var *var)
{
	int	i;

	i = ft_strlen(var->line) + 2;
	return (i);
}

t_var	*setup_var(t_var *var)
{
	struct winsize ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	var = (t_var*)ft_memalloc(sizeof(t_var));
	var->hist = (char **)ft_memalloc(sizeof(char *));
	var->line = ft_strdup("\0");
	var->index = 0;
	var->col = ws.ws_col;
	var->multiline = len_line(var) / var->col;
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
	ft_putstr_fd(tgetstr("vi", NULL), 1);
}

void	setup_env(int ac, char **av, t_env *env)
{
	(void)ac;
	(void)av;
	setup_term(env);
}
