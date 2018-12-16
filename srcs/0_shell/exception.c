/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:27:05 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/16 18:49:04 by hben-yah         ###   ########.fr       */
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

int		pipe_exception(void)
{
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"pipe error\n");
	return (0);
}

int		fork_exception(void)
{
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"fork error\n");
	return (0);
}

int		file_permission_exception(char *file)
{
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"permission denied: %s\n", file);
	return (0);
}

int		fd_exception(char *fd)
{
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"%s : bad file descriptor\n", fd);
	return (0);
}
