/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:47:21 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/08 01:50:58 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_p(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	add(sb, "0x", 2);
	fmt->length = 3 << ft_indexof('l', LENGTHS);
	return (unsigned_integer(fmt, sb, ap, 16));
}
