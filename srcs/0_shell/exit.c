/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:28:20 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 18:43:44 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	exit_program(char *message)
{
	t_data *data;

	data = get_data();
	reset_shell(data);
	if (message)
	{
		ft_dprintf(STDERR_FILENO, message);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
