/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:54:11 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/19 14:19:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		display_prompt(void)
{
	// afficher user ?
	// afficher le rep courant 
	if (ft_strequ(get_variable("?"), "0"))
		ft_printf("%s » %s", "", ""); // bleu
	else
		ft_putstr_col(" » ", "", ""); // rouge
}

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
	data->term_dft_config = term;
	/*term.c_lflag ^= ICANON;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &term);*/
	init_sig();
	try_m((data->env = newvartab(env)));
	try_m((data->loc = newvartab(NULL)));
}

void	command_line_loop()
{
	t_data	*data;

	data = get_data();
	while (!data->shell_exit)
	{
		display_prompt();
		read_command_line();
		if (!data->errno && !(data->errno = 0))
		{
			lexical_analyse();
			if (!parse())
			{
				create_ast();
				execute();
			}
		}
		else
		{
			// free lex
			// mettre retour à > 0
		}
		ft_printf("\n");
	}	
}

int		shell(int ac, char **av, char **env)
{
	if (ac && av)
	{
		init_shell(env);
		command_line_loop();
		// free des trucs
	}
	return (EXIT_SUCCESS);
}
