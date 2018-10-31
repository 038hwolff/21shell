/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:22:35 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 15:17:02 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	trial(int i)
{
	if (!i)
		exit(EXIT_FAILURE);
}

void	cmd_not_found(t_data *data)
{
	ft_putstr("21sh: command not found: ");
	ft_putendl(data->args[0]);
	exit(EXIT_FAILURE);
}
