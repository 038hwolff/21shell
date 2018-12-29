/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:27:05 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/29 18:25:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	*try_m(void *ptr)
{
	if (!ptr)
		exit_program(""ERR_PREFIX"memory allocation error\n");
	return (ptr);
}

void	term_exception(char *message)
{
	ft_dprintf(STDERR_FILENO, message);
	exit(EXIT_FAILURE);
}

void	tent_exception(char *ent)
{
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"no entry for terminal -- %s\n", ent);
	exit(EXIT_FAILURE);
}

int		syntax_exception(char *word, int subcmd)
{
	if (word)
	{
		ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"%sparse error near `%s'\n",
									(subcmd ? "command substitution: " : ""), word);
		return (1);
	}
	return (0);
}

int		eof_exception(int subcmd)
{
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"%sunexpected end of file\n",
									(subcmd ? "command substitution: " : ""));
	return (0);
}
