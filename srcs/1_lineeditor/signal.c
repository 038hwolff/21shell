/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:18:09 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 09:25:17 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	signal_handler(int signall)
{
	t_data	*data;

	data = get_data();
	if (signall == SIGINT)
	{
		data->sigint = 1;
		ft_putchar_fd('\n', 1);
		display_prompt(data->prompt);
		ft_strdel(&data->edl.line);
		try_m(data->edl.line = ft_strnew(0));
		data->edl.index = 0;
		signal(SIGINT, signal_handler);
	}
}

void	signal_list(void)
{
	int	i;

	i = -1;
	while (++i < 32)
		signal(i, signal_handler);

}

int		check_eof(t_data *data)
{
	return (data->eof != 0 && !(data->shell_exit = 0) && !(data->eof = 0));
}
