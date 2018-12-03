/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:26:20 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/03 21:28:52 by hben-yah         ###   ########.fr       */
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

void	display_prompt(char *prompt)
{
	/*t_data *data;

	data = get_data();
	if (data->prompt)
		ft_printf("%s\n", data->prompt);
	data->prompt = NULL;*/
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
