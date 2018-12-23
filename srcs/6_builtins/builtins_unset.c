/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:36:04 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/23 18:10:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		b_unset(t_data *data, char **args)
{
	int		i;

	i = 0;
	while (args[++i])
	{
		var_unset(&data->env, args[i]);
		var_unset(&data->loc, args[i]);
		++i;
	}
	if (i == 1)
	{
		ft_dprintf(STDERR_FILENO, "unset: not enough arguments\n");
		return (0);
	}
	return (1);
}
