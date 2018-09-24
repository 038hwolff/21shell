/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:31:26 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/10 14:20:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_n(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	void	*arg;

	if (!(arg = va_arg(ap, void *)))
		return (0);
	fmt->precision = -1;
	fmt->width = 0;
	if (is_length('h', *fmt, 3) == 3)
		*(char *)arg = (char)(sb->length + fmt->prev_len);
	else if (is_length('h', *fmt, 1) == 1)
		*(short *)arg = (short)(sb->length + fmt->prev_len);
	else if (is_length('l', *fmt, 1) == 4)
		*(long *)arg = (long)(sb->length + fmt->prev_len);
	else if (is_length('l', *fmt, 3) == 12)
		*(long long *)arg = (long long)(sb->length + fmt->prev_len);
	else if (is_length('j', *fmt, 1) == 16)
		*(intmax_t *)arg = (intmax_t)(sb->length + fmt->prev_len);
	else if (is_length('t', *fmt, 1) == 32)
		*(ptrdiff_t *)arg = (ptrdiff_t)(sb->length + fmt->prev_len);
	else if (is_length('z', *fmt, 1) == 64)
		*(long *)arg = (long)(sb->length + fmt->prev_len);
	else
		*(int *)arg = (int)(sb->length + fmt->prev_len);
	return (0);
}

int		set_coma(t_strbuffer *sb, int len)
{
	static t_strbuffer	tmp = (t_strbuffer){NULL, 0, 0};
	int					i;

	i = 0;
	while (len-- && sb->length && ft_isdigit(*(sb->str + sb->length - 1)))
	{
		add(&tmp, sb->str + --sb->length, 1);
		if (++i % 3 == 0 && len)
			add(&tmp, ",", 1);
	}
	while (tmp.length)
		add(sb, tmp.str + --tmp.length, 1);
	tmp.length = 0;
	return (i / 3);
}
