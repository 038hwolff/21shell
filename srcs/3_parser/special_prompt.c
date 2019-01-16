/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:25:36 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/16 19:43:42 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	set_prompt(t_data *data, char *prompt, size_t prompt_len)
{
	data->edl.prompt = prompt;
	data->edl.prompt_len = prompt_len;
}

void	set_special_prompt(t_data *data)
{
	if (data->incomp_type == INC_QUOTE)
		set_prompt(data, PQUOTE, PQUOTE_LEN);
	else if (data->incomp_type == INC_DQUOTE)
		set_prompt(data, PDQUOTE, PDQUOTE_LEN);
	else if (data->incomp_type == INC_BKSLASH)
		set_prompt(data, PBACKSLASH, PBACKSLASH_LEN);
	else if (data->incomp_type == INC_HEREDOC)
		set_prompt(data, PHEREDOC, PHEREDOC_LEN);
	else if (data->incomp_type == INC_PARENT)
		set_prompt(data, PPARENT, PPARENT_LEN);
	else if (data->incomp_type == INC_BKQUOTE)
		set_prompt(data, PBQUOTE, PBQUOTE_LEN);
	else if (data->incomp_type == INC_DAND)
		set_prompt(data, PDAND, PDAND_LEN);
	else if (data->incomp_type == INC_DPIPE)
		set_prompt(data, PDPIPE, PDPIPE_LEN);
	else if (data->incomp_type == INC_PIPE)
		set_prompt(data, PPIPE, PPIPE_LEN);
	else if (data->incomp_type == COMPLETE)
		set_prompt(data, PDEFAULT, PDEFAULT_LEN);
}
