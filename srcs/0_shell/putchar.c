/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:26:54 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/15 14:20:14 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Pour put des valeurs issues de termcaps dans le terminal.
*/

int		sh_putchar(int c)
{
	return (write(0, &c, 1));
}
