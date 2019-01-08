/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:26:20 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/08 21:18:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	display_prompt(t_edl *edl)
{
	if (edl->prompt)
	{
		ft_putstr_fd(tgetstr("me", NULL), 1);
		ft_putstr_fd(edl->prompt, 1);
	}
}
