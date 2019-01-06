/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:26:20 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/30 22:28:18 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	display_prompt(char *prompt)
{
	if (prompt != NULL)
	{
		ft_putstr_fd(tgetstr("me", NULL), 1);
		ft_putstr_fd(prompt, 1);
		return ;
	}
	ft_putstr_fd(tgetstr("me", NULL), 1);
	ft_putstr_fd("$>", 1);
	return ;
}
