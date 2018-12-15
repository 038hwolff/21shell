/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:27:23 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/15 14:16:29 by hwolff           ###   ########.fr       */
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
