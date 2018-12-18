/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:53:55 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 14:53:56 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_cancel(t_data *data, char **line)
{
	if (check_if_sigint(data, line))
		return (1);
	if (check_eof(data))
	{
		eof_exception();
		ft_strdel(line);
		return (1);
	}
	return (0);
}
