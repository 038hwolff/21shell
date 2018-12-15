/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:19:07 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 16:37:37 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		b_env(t_data *data)
{
	int		i;
	t_data	ndata;

	i = 1;
	while (data->args[i] && data->args[i][0] == '-')
		i++;
	trial((int)(ndata.env = ft_tabdup(data->env, 0)));
	while (data->args[i] && ft_strchr(data->args[i], '='))
		add_to_env(&ndata, data, i++);
	if (data->args[i])
	{
		trial((int)(ndata.args = ft_tabdup(data->args + i, 0)));
		ex_exec(&ndata);
		free_tab(&ndata.args);
	}
	else
		ft_putstrtab(ndata.env);
	free_tab(&ndata.env);
	return (1);
}
