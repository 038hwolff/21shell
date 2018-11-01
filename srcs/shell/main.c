/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:54:11 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/01 12:03:56 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		main(int ac, char **av, char **env)
{
	char *arg;

	if (ac == 2)
	{
		if (ft_strequ(av[1], "mini"))
		{
			arg = "minishell";
			minishell(1, &arg, env);
		}
		else
		{
			arg = "21sh";
			shell(1, &arg, env);
		}
	}
	return (EXIT_SUCCESS);
}