/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:34:31 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/08 14:14:06 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_char(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	unsigned char	chara;

	if (is_length('l', *fmt, 1))
		return (convert_wchar(fmt, sb, ap));
	chara = (unsigned char)va_arg(ap, unsigned);
	fmt->precision = -1;
	add(sb, (void *)&chara, 1);
	return (1);
}

int		convert_wchar(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	wint_t			chara;
	size_t			ret;

	chara = va_arg(ap, wint_t);
	fmt->precision = -1;
	trial(sb_check_free_space(sb, 4));
	if (!check_unicode(&chara)
		|| !(ret = wchartoa(sb->str + sb->length, chara)))
		return (-1);
	sb->length += ret;
	return ((int)ret);
}
