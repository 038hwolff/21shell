/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:09:48 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 20:38:22 by hben-yah         ###   ########.fr       */
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
	reset_command(data);
	free_tab(&data->env);
	free_tab(&data->loc);

	// ne pas free data->temr_name (non malloc)

}

void	reset_command(t_data *data)
{
	if (data->ast)
		free_ast(&data->ast);	
	else if (data->token)
		free_token(&data->token);
	data->ast = NULL;	
	data->token = NULL;
	data->eof = 0;
	data->sigint = 0;
	if (data->edl.line)
		ft_strdel(&data->edl.line);
}
