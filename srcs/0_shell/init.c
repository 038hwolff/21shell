/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:28:15 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/10 12:01:45 by hben-yah         ###   ########.fr       */
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

char	*inline_args(int ac, char **av)
{
	char	*res;
	char	*tmp;
	int		i;

	res = NULL;
	if (ac > 0)
	{
		try_m(res = ft_strnew(0));
		i = 0;
		while (i < ac)
		{
			try_m(tmp = ft_strjoin(res, av[i]));
			ft_strdel(&res);
			res = tmp;
			++i;
		}
	}
	return (res);
}

void	init_shell(char **env, int ac, char **av, int dev)
{
	t_data			*data;
	struct termios	term;
	char			*input;

	data = get_data();
	input = NULL;
	if (!isatty(STDIN_FILENO))
		input = read_fd(0);
	if (tcgetattr(STDIN_FILENO, &term) == -1 && !input)
		term_exception("could not get terminal config");
	dev && (data->dev = 1);
	try_m((data->env = ft_strtabdup(env)));
	try_m((data->loc = ft_strtabnew(0)));
	try_m((data->spe = ft_strtabnew(0)));
	var_set(&data->spe, "?", "0");
	data->arguments = inline_args(ac, av);
	var_set(&data->spe, "?", "0");
	if (input)
		exit(subshell(data, 1, &input));
	data->term_dft_config = term;
	check_term(data);
	set_prompt(data, PDEFAULT, PDEFAULT_LEN);
}
