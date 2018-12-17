/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:28:15 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 18:44:33 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_term(t_data *data)
{
	struct termios	term;

	term = data->term_dft_config;
	term.c_lflag ^= ICANON | ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &term);
}

/*
** Initialisation du shell
** - de la structure data
** - on verifie le terminal
** - on intercepte les signaux
*/

void	init_shell(char **env)
{
	t_data			*data;
	struct termios	term;

	data = get_data();
	if (tcgetattr(STDIN_FILENO, &term) == -1)
		term_exception(""ERR_PREFIX"could not get terminal config\n");
	data->term_dft_config = term;
	try_m((data->env = ft_strtabdup(env)));
	try_m((data->loc = ft_strtabnew(0)));
	check_term(data);
	init_term(data);
	init_sig();
}
