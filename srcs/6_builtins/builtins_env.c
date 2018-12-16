/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:19:07 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/15 22:54:05 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		b_env(char **env, char **arg)
{
	int		i;
	char	**nenv;
	char 	**narg;

	i = 1;
	while (arg[i] && arg[i][0] == '-')
		i++;
	try_m((nenv = ft_strtabdup(env)));
	while (arg[i] && ft_strchr(arg[i], '='))
		add_to_env(nenv, arg, i++);
	if (arg[i])
	{
		try_m((narg = ft_strtabdup(arg + i)));
		ex_exec(nenv, narg);
		free_tab(&narg);
	}
	else
		ft_putstrtab(nenv);
	free_tab(&nenv);
	return (1);
}
