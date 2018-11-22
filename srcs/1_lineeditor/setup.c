/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:45:59 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/22 22:09:45 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	len_line(t_edl *edl)
{
	int	i;

	i = ft_strlen(edl->line) + 2;
	return (i);
}

t_edl	*setup_edl(t_edl *edl)
{
	struct winsize ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	//edl = (t_edl*)ft_memalloc(sizeof(t_edl));
	edl->hist = (char **)ft_memalloc(sizeof(char *));
	edl->line = ft_strdup("\0");
	edl->index = 0;
	edl->col = ws.ws_col;
	edl->multiline = len_line(edl) / edl->col;
	edl->h_count = 0;
	edl->h_current = 0;
	return (edl);
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
