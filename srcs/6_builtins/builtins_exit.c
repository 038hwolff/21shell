/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:46:23 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/06 17:27:54 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_is_number(char *s)
{
	if (*s && *s != ' ')
	{
		while (*s && *s != ' ')
		{
			if (!ft_isdigit(*s))
				return (0);
			++s;
		}
		return (1);
	}
	return (0);
}

int		b_exit(t_data *data, char **arg)
{
	int ret;
	int	ac;

	ret = RET_OK;
	ac = ft_strtablen(arg);
	if (ac > 2)
		return (put_exception(RET_ERROR, "exit", NULL, "too many arguments"));
	else if (ac == 2)
	{
		if (!ft_is_number(arg[1]))
			exit_program(put_exception(255, "exit", arg[1],
										"numeric argument required"));
		ret = ft_atoi(arg[1]) % 256;
		(ret < 0) && (ret += 256);
		exit_program(ret);
	}
	else
		exit_program(ft_atoi(var_get_val(data->spe, "?")));
	return (ret);
}
