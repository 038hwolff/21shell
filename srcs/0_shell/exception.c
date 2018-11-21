/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:27:05 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/21 15:04:18 by hben-yah         ###   ########.fr       */
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
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"no entry for terminal name -- %s\n", ent);
	exit(EXIT_FAILURE);
}

void	syntax_exception(char *word)
{
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"parse error near `%s'\n", word);
}
