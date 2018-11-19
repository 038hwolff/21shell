/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:28:20 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/11 00:17:34 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	exit_program(char *message)
{
	//t_data *data;

	//data = get_data();
	//reset_shell(data);
	//free_data(data);
	if (message)
	{
		ft_dprintf(STDERR_FILENO, message);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}