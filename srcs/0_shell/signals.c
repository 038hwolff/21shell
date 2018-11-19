/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:27:49 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/19 17:03:45 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** interception de signaux pour ne rien faire
*/
void	init_sig()
{
	int	i;

	i = 1;
	while (i < 32)
		signal(i++, SIG_IGN);
	signal(SIGTERM, SIG_DFL);
}