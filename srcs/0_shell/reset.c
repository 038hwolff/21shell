/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:38:11 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/14 14:15:49 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	reset_term(t_data *data)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &data->term_dft_config);
}

void	reset_shell(t_data *data)
{
	if (!data->subcmd && data->term_name)
		reset_term(data);
	reset_subshell(data);
}

void	reset_subshell(t_data *data)
{
	reset_command(data);
	if (data->env)
		free_tab(&data->env);
	if (data->loc)
		free_tab(&data->loc);
	if (data->spe)
		free_tab(&data->spe);
	if (data->arguments)
		ft_strdel(&data->arguments);
	free(data);
}

void	reset_command(t_data *data)
{
	if (data->ast)
		free_ast(&data->ast);
	if (data->token)
		free_token(&data->token);
	if (data->command)
		ft_strdel(&data->command);
	data->ast = NULL;
	data->token = NULL;
	data->eof = 0;
	data->sigint = 0;
	if (data->edl.line)
		ft_strdel(&data->edl.line);
}
