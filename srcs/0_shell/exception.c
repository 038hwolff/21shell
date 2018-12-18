/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:27:05 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/18 08:30:59 by hwolff           ###   ########.fr       */
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

int		syntax_exception(char *word)
{
	if (word)
	{
		ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"parse error near `%s'\n", word);
		return (1);
	}
	return (0);
}

int		eof_exception(void)
{
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"abrupt end of file\n");
	return (0);
}
