/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:27:05 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/06 15:15:16 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	*try_m(void *ptr)
{
	if (!ptr)
		exit_program(put_exception(RET_ERROR, NULL, NULL, "memory allocation error"));
	return (ptr);
}

void	term_exception(char *message)
{
	put_exception(RET_ERROR, NULL, NULL, message);
	exit(RET_ERROR);
}

void	tent_exception(char *ent)
{
	put_exception(RET_ERROR, NULL, ent, "no entry for terminal");
	exit(RET_ERROR);
}

int		syntax_exception(char *word, int subcmd)
{
	if (word)
	{
		ft_dprintf(STDERR_FILENO, ""SH_NAME": %sparse error near `%s'\n",
									(subcmd ? "command substitution: " : ""), word);
		return (1);
	}
	return (0);
}

int		put_exception(int ret, char *prog, char *arg, char *message)
{
	if (message)
	{
		if (prog)
		{
			if (arg)
				ft_dprintf(STDERR_FILENO, ""SH_NAME": %s: %s: %s\n", prog, arg, message);				
			else
				ft_dprintf(STDERR_FILENO, ""SH_NAME": %s: %s\n", prog, message);
		}
		else
		{
			if (arg)
				ft_dprintf(STDERR_FILENO, ""SH_NAME": %s: %s\n", arg, message);
			else
				ft_dprintf(STDERR_FILENO, ""SH_NAME": %s\n", message);
		}
	}
	return (ret);
}
