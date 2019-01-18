/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:19:07 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/18 17:04:47 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		b_env(t_data *data, char **arg)
{
	int		i;
	char	**nenv;
	char	**narg;
	int		ret;

	i = 1;
	ret = RET_OK;
	while (arg[i] && arg[i][0] == '-')
		i++;
	try_m((nenv = ft_strtabdup(data->env)));
	while (arg[i] && ft_strchr(arg[i], '='))
		var_set_line(&nenv, arg[i++]);
	if (arg[i])
	{
		try_m((narg = ft_strtabdup(arg + i)));
		ret = ex_exec(data, nenv, narg);
		free_tab(&narg);
	}
	else
		ft_putstrtab(nenv);
	free_tab(&nenv);
	return (ret);
}
