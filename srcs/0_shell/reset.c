/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:09:48 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 18:44:07 by hwolff           ###   ########.fr       */
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
	ft_strdel(&data->edl.line);
}
