/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:48:37 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/21 15:48:06 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		parse(t_data *data, t_token *tokens)
{
	char *word;

	(void)data;

	ft_printf("raf");
	if (!tokens)
		return (0);
	if ((word = check_syntax(tokens)))
	{
		syntax_exception(word);
		return (0);
	}

	//if (!check_inhibitors(data, tokens))
	//	return (0);

	return (1);
}