/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_printable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:50:50 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/08 15:26:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	print_non_printable(t_strbuffer *sb, char *str, size_t n)
{
	const char *base = "0123456789abcdef";

	while (*str && n--)
	{
		if (*str < ' ' || *str == 127)
		{
			add(sb, "\\", 1);
			add(sb, &base[*str / 16], 1);
			add(sb, &base[*str % 16], 1);
		}
		else
			add(sb, str, 1);
		++str;
	}
}

int	convert_r(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	char	*str;
	int		ret;

	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	if (fmt->precision <= -1)
		ret = ft_strlen(str);
	else
		ret = ft_min(ft_strlen(str), fmt->precision);
	fmt->precision = -1;
	print_non_printable(sb, str, ret);
	return (ret);
}
