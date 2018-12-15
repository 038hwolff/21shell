/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:09:48 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/15 16:23:39 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	reset_term(t_data *data)
{	
	tcsetattr(STDIN_FILENO, TCSANOW, &data->term_dft_config);
}

void	reset_shell(t_data *data)
{	
	reset_term(data);
}
