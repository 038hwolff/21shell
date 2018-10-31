/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:41:46 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/08 15:30:32 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_di(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	return (signed_integer(fmt, sb, ap, 10));
}

int		convert_u(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	return (unsigned_integer(fmt, sb, ap, 10));
}

int		convert_x(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	if (is_flag('#', *fmt))
	{
		if (fmt->converter == 'X')
			add(sb, "0X", 2);
		else
			add(sb, "0x", 2);
	}
	return (unsigned_integer(fmt, sb, ap, 16));
}

int		convert_o(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	int alt;

	if ((alt = is_flag('#', *fmt)))
		add(sb, "0", 1);
	fmt->converter = 'o';
	return (unsigned_integer(fmt, sb, ap, 8) + alt);
}

int		convert_b(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	if (is_flag('#', *fmt))
		add(sb, "b", 1);
	return (unsigned_integer(fmt, sb, ap, 2));
}
