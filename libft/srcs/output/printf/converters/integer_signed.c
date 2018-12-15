/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:16:35 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/10 15:07:12 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	itoa_base(t_strbuffer *sb, intmax_t i, int base, char upcase)
{
	const char	*a = (upcase ? "0123456789ABCDEF" : "0123456789abcdef");
	int			ret;

	ret = 1;
	if (i <= -base || base <= i)
		ret += itoa_base(sb, i / base, base, upcase);
	add(sb, a + ft_abs(i % base), 1);
	return (ret);
}

static intmax_t
	get_arg(va_list ap, t_formatter *fmt)
{
	intmax_t	arg;

	if (is_length('h', *fmt, 3) == 3)
		arg = (char)va_arg(ap, int);
	else if (is_length('h', *fmt, 1) == 1)
		arg = (short)va_arg(ap, int);
	else if (is_length('l', *fmt, 1) == 4)
		arg = va_arg(ap, long);
	else if (is_length('l', *fmt, 3) == 12)
		arg = va_arg(ap, long long);
	else if (is_length('j', *fmt, 1) == 16)
		arg = va_arg(ap, intmax_t);
	else if (is_length('t', *fmt, 1) == 32)
		arg = va_arg(ap, ptrdiff_t);
	else if (is_length('z', *fmt, 1) == 64)
		arg = va_arg(ap, long);
	else
		arg = va_arg(ap, int);
	return (arg);
}

int	signed_integer(t_formatter *fmt, t_strbuffer *sb, va_list ap, int b)
{
	intmax_t	arg;
	int			ret;

	arg = get_arg(ap, fmt);
	if (arg < 0)
		add(sb, "-", 1);
	else if (is_flag('+', *fmt))
		add(sb, "+", 1);
	else if (is_flag(' ', *fmt))
		add(sb, " ", 1);
	if (arg == 0 && fmt->precision == 0)
		return (0);
	ret = itoa_base(sb, arg, ft_abs(b), ft_isupper(fmt->converter));
	if (b == 10 && is_flag('\'', *fmt))
		ret += set_coma(sb, ret);
	return (ret);
}
