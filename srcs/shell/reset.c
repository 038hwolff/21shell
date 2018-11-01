/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:32:53 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/01 16:38:25 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void
	reset_shell(t_data *data)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &data->prev_term);
	tputs(tgetstr("ve", NULL), 1, sh_putchar);
	tputs(tgetstr("te", NULL), 1, sh_putchar);
}