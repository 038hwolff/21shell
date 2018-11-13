/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:18:45 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/13 18:18:46 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/shell.h"

//GERER LE SURLIGNEMENT DU CURRENT?
void	mouve_left(t_var *var)
{
	var->index--;
	ft_putstr_fd(tgetstr("le", NULL), 2);
}

void	mouve_right(t_var *var)
{
	var->index++;
	ft_putstr_fd(tgetstr("nd", NULL), 2);	
}
