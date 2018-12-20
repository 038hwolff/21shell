/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:45:13 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/20 13:44:28 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"%s: Permission denied\n", file);
	return (0);
}

int		fd_exception(char *fd)
{
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"%s : bad file descriptor\n", fd);
	return (0);
}

int		cmd_not_found_exception(char *cmd)
{
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"%s: command not found\n", cmd);
	return (0);
}

int		file_not_found_exception(char *file)
{
	ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"%s: No such file or directory\n", file);
	return (0);
}
