/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:28:15 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/08 21:14:37 by hben-yah         ###   ########.fr       */
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

void	set_pwd_value(t_data *data)
{
	char	*s;

	s = NULL;
	try_m(s = getcwd(s, 0));
	var_set(&data->env, "PWD", s);
	ft_strdel(&s);
}

void	init_shell(char **env, int dev)
{
	t_data			*data;
	struct termios	term;

	data = get_data();
	if (tcgetattr(STDIN_FILENO, &term) == -1)
		term_exception(""SH_NAME"could not get terminal config\n");
	data->term_dft_config = term;
	dev && (data->dev = 1);
	try_m((data->env = ft_strtabdup(env)));
	try_m((data->loc = ft_strtabnew(0)));
	try_m((data->spe = ft_strtabnew(0)));
	var_set(&data->spe, "?", "0");
	check_term(data);
	init_term(data);
	set_prompt(data, PDEFAULT, PDEFAULT_LEN);
}
