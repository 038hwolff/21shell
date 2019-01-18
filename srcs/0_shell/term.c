/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:27:23 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/18 17:08:01 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** On verifie le terminal, qu'on ait son nom, que c'est bien un terminal,
** et au'il ait bien une entrée à son nom dans la base de données
** terminfo pour l'utilisation des termcaps.
*/

void	check_term(t_data *data)
{
	char	buff[1024];
	int		ret;

	if (!(data->term_name = getenv("TERM")))
	{
		data->term_name = DEFAULT_TERM;
		var_set(&data->env, "TERM", data->term_name);
	}
	if (!isatty(STDIN_FILENO)
		|| !isatty(STDOUT_FILENO)
		|| !isatty(STDERR_FILENO))
		term_exception("std I/O doesn't refer to a terminal\n");
	if ((ret = tgetent(buff, data->term_name)) == 0)
		tent_exception(data->term_name);
	else if (ret == -1)
		term_exception("terminfo database not found\n");
}
