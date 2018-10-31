/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:52:34 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/08 15:27:17 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	print_hexadecimal(const unsigned char *s, size_t size, size_t i,
														t_strbuffer *sb)
{
	const char	*base = "0123456789ABCDEF";
	size_t		j;

	j = 0;
	while (j < 16 && j + i < size)
	{
		add(sb, &base[*(s + i + j) / 16], 1);
		add(sb, &base[*(s + i + j) % 16], 1);
		if (j % 2 == 1)
			add(sb, " ", 1);
		++j;
	}
	while (j < 16)
	{
		add(sb, "  ", 2);
		if (j % 2 == 1)
			add(sb, " ", 1);
		++j;
	}
}

static void
	print_memory(const void *addr, size_t size, t_strbuffer *sb)
{
	const unsigned char	*s = (unsigned char *)addr;
	size_t				i;
	size_t				j;

	i = 0;
	if (sb->length > 0)
		add(sb, "\n", 1);
	while (i < size)
	{
		print_hexadecimal(s, size, i, sb);
		j = -1;
		while (++j < 16 && j + i < size)
			if (ft_isprint(*(s + i + j)))
				add(sb, (const char *)(s + i + j), 1);
			else
				add(sb, ".", 1);
		add(sb, "\n", 1);
		i += 16;
	}
}

int	convert_m(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	int		*arg;
	size_t	beg;
	size_t	end;

	arg = va_arg(ap, int *);
	beg = sb->length;
	print_memory(arg, fmt->width, sb);
	end = sb->length;
	return (end - beg);
}
