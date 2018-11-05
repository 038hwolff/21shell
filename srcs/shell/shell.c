/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:54:11 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/05 17:32:49 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Pattern singleton pour récupérer la structure de données du shell
*/
t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
		data = (t_data*)ft_memalloc(sizeof(t_data));
	return (data);
}

/*
** Pour put des valeurs issues de termcaps dans le terminal.
*/
int		sh_putchar(int c)
{
	return (write(0, &c, 1));
}

/*
** On verifie le terminal, qu'on ait son nom, que c'est bien un terminal,
** et au'il ait bien une entrée à son nom dans la base de données
** terminfo pour l'utilisation des termcaps.
**
*/
static void
	check_term(t_data *data)
{
	char	buff[1024];
	int		ret;

	if (!(data->term_name = getenv("TERM")))
		term_exception(""ERR_PREFIX"could not get the terminal name\n");
	if (!isatty(STDIN_FILENO)
		|| !isatty(STDOUT_FILENO)
		|| !isatty(STDERR_FILENO))
		term_exception(""ERR_PREFIX"standard I/O don't refer to a terminal\n");
	if ((ret = tgetent(buff, data->term_name)) == 0)
		tent_exception(data->term_name);
	else if (ret == -1)
		term_exception(""ERR_PREFIX"terminfo database not found\n");
}

/*
** interception de signaux pour ne rien faire
*/
void	init_sig()
{
	int	i;

	i = 1;
	while (i < 32)
		signal(i, SIG_IGN);
	signal(SIGTERM, SIG_DFL);
}


/*
** Initialisation du shell
** - de la structure data
** - on verifie le terminal
** - mode non canonique (pas de bufferisation de ce au'on tape)
** - on intercepte les signaux
** 
*/
void	init_shell(char **env)
{
	t_data			*data;
	struct termios	term;

	data = get_data();
	check_term(data);
	if (tcgetattr(STDIN_FILENO, &term) == -1)
		term_exception(""ERR_PREFIX"could not get terminal config\n");
	data->prev_term = term;
	term.c_lflag ^= ICANON;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &term);
	init_sig();
	try_m((data->env = ft_strtabdup(env)));
}

int		shell(int ac, char **av, char **env)
{
	t_data *data;

	if (ac && av)
	{
		data = get_data();
		init_shell(env);
	
		while (data->on)
		{
			//while (read_input() == -1)
			//	;
		//lex_input();
		//if (parse_input())
			//execute_input();
			ft_printf("\n");
		}	
	}
	return (EXIT_SUCCESS);
}
