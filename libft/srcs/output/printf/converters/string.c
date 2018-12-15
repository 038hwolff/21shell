/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:12:42 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/08 12:54:10 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_str(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	char	*str;
	int		ret;

	if (is_length('l', *fmt, 1))
		return (convert_wstr(fmt, sb, ap));
	else if (!(str = va_arg(ap, char *)))
		str = "(null)";
	if (fmt->precision <= -1)
		ret = ft_strlen(str);
	else
		ret = ft_min(ft_strlen(str), fmt->precision);
	fmt->precision = -1;
	add(sb, str, ret);
	return (ret);
}

int		convert_wstr(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	wchar_t	*wstr;
	int		ret;
	wchar_t	*a;
	int		i;

	i = 0;
	if (!(wstr = va_arg(ap, wchar_t *)))
		wstr = L"(null)";
	a = wstr;
	while (*a && (fmt->precision == -1 || i < fmt->precision))
		if (i++ && !check_unicode((wint_t *)a++))
			return (-1);
	trial(sb_check_free_space(sb, 4 * (a - wstr)));
	if (fmt->precision > -1)
		ret = wstrntoa(sb->str + sb->length, wstr, fmt->precision);
	else
		ret = wstrtoa(sb->str + sb->length, wstr);
	sb->length += ret;
	fmt->precision = -1;
	return (ret);
}
