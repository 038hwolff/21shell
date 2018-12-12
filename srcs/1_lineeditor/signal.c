/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:18:09 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/13 18:18:12 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/shell.h"

void	signal_handler(int signall)
{
	t_data	*data;

	data = get_data();
	if (signall == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		display_prompt(data->prompt);
		free(data->edl.line);
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
