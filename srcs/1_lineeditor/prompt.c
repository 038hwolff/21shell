/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:26:20 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/30 14:23:40 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*void		displ_prompt(void)
{
	// afficher user ?
	// afficher le rep courant 
	if (ft_strequ(get_variable("?"), "0"))
		ft_printf("%s » %s", "", ""); // bleu
	else
		ft_printf("%s » %s", "", ""); // rouge
}*/

void	display_prompt(void)
{
	ft_putstr_fd(tgetstr("me", NULL), 1);
	ft_putstr_fd("$>", 1);
	return ;
}
