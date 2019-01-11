/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:53:55 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/11 19:22:15 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_eof(t_data *data)
{
	return (data->eof);
}

int		check_if_sigint(t_data *data, char **line)
{
	if (line && *line
		&& data->sigint == 1)
	{
		data->sigint = 0;
		return (1);
	}
	return (0);
}

int		check_cancel(t_data *data, char **line)
{
	if (check_if_sigint(data, line))
		return (1);
	if (data->eof)
	{
		ft_putchar('\n');
		put_exception(0, "syntax error", NULL, "unexpected end of file");
		data->eof = 0;
		set_prompt(data, PDEFAULT, PDEFAULT_LEN);
		return (2);
	}
	return (0);
}
