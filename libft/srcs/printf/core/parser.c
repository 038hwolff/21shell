/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 19:31:09 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/10 15:03:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	set_width(const char **s, t_formatter *fmt)
{
	fmt->width = 0;
	while ('0' <= **s && **s <= '9')
		fmt->width = (10 * fmt->width) + *((*s)++) - '0';
	--(*s);
}

static void
	set_width_from_arg(const char **s, t_formatter *fmt, t_arglist *args)
{
	int		nwidth;
	int		i;
	va_list tmp;

	va_copy(tmp, args->begin);
	++(*s);
	nwidth = 0;
	while ('0' <= **s && **s <= '9')
		nwidth = (10 * nwidth) + *((*s)++) - '0';
	if (**s == '$')
	{
		i = nwidth;
		while (i--)
			fmt->width = va_arg(tmp, unsigned);
	}
	else
	{
		fmt->width = va_arg(args->natural, unsigned);
		if (nwidth > 0)
			fmt->width = nwidth;
		--(*s);
	}
}

static void
	set_length_modifier(char c, t_formatter *fmt)
{
	if (c == 'h' && is_length('h', *fmt, 1))
		fmt->length |= 1 << (ft_indexof('h', LENGTHS) + 1);
	else if (c == 'l' && is_length('l', *fmt, 1))
		fmt->length |= 1 << (ft_indexof('l', LENGTHS) + 1);
	else if (fmt->length == 0 || !(c == 'h' && is_length('h', *fmt, 3) != 3))
		fmt->length = 1 << ft_indexof(c, LENGTHS);
}

static void
	set_precision(const char **s, t_formatter *fmt, t_arglist *args)
{
	if (*(++(*s)) == '*')
		fmt->precision = va_arg(args->natural, unsigned);
	else
	{
		fmt->precision = 0;
		while ('0' <= **s && **s <= '9')
			fmt->precision = (10 * fmt->precision) + *((*s)++) - '0';
		--(*s);
	}
}

void
	parse_formatter(const char **s, t_formatter *fmt, t_arglist *args)
{
	*fmt = (t_formatter){0, 0, 0, -1, 0, 0, 0, 0};
	while (*(++(*s)))
		if ('1' <= **s && **s <= '9')
			set_width(s, fmt);
		else if (**s == '*')
			set_width_from_arg(s, fmt, args);
		else if (ft_indexof(**s, FLAGS) >= 0)
			fmt->flags |= (1 << ft_indexof(**s, FLAGS));
		else if (ft_indexof(**s, LENGTHS) >= 0)
			set_length_modifier(**s, fmt);
		else if (**s == '.')
			set_precision(s, fmt, args);
		else if (**s == '$')
			(fmt->pos == 0) && (fmt->pos = fmt->width)
			&& (fmt->width = 0);
		else if ((fmt->converter = **s) && ++(*s))
			break ;
}
