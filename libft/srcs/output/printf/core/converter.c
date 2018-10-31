/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:25:58 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/10 13:47:32 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	convert_without_prec(t_strbuffer *sb, t_formatter *fmt, t_arglist *args)
{
	const void	*f[] = {
		&convert_di, &convert_di, &convert_di, &convert_o, &convert_o,
		&convert_u, &convert_u, &convert_x, &convert_x, &convert_char,
		&convert_wchar, &convert_str, &convert_wstr, &convert_p, &convert_b,
		&convert_n, &convert_q, &convert_q_up, &convert_k, &convert_m,
		&convert_r};
	int			conv_id;

	if (ft_indexof(fmt->converter, LONG_NUMERICS) > -1)
		fmt->length = 1 << ft_indexof('l', LENGTHS);
	if ((conv_id = ft_indexof(fmt->converter, CONVERTERS)) <= -1)
	{
		add(sb, &fmt->converter, 1);
		fmt->precision = -1;
		return (1);
	}
	return (((int (*)())f[conv_id])(fmt, sb, fmt->pos ? args->selected
															: args->natural));
}

static int
	fill_precision(t_strbuffer *sb, t_formatter *fmt, int conv_ret,
													t_conversion *conv)
{
	conv->len = conv_ret;
	if (conv->len < fmt->precision && ft_indexof(fmt->converter, NUMERICS) > -1)
	{
		while (conv->len < fmt->precision && ++conv->len)
			add(sb, "0", 1);
		trial(sb_slide(sb, conv->end - conv_ret, conv->end));
	}
	return (conv->len);
}

static int
	convert_without_width(t_strbuffer *sb, t_formatter *fmt, t_arglist *args)
{
	t_conversion	conv;
	int				ret;

	if ((ret = convert_without_prec(sb, fmt, args)) == -1)
		return (-1);
	conv.end = sb->length;
	if (fmt->width < 0 && fmt->precision == -1)
		(fmt->width = ft_abs(fmt->width))
		&& (fmt->flags |= 1 << ft_indexof('-', FLAGS));
	ret = fill_precision(sb, fmt, ret, &conv);
	return (ret);
}

static void
	fill_width(t_strbuffer *sb, t_formatter *fmt, int conv_ret,
												t_conversion *conv)
{
	if (conv->len <= fmt->width && conv_ret != -1)
	{
		if (is_flag('0', *fmt) && !is_flag('-', *fmt) && fmt->precision <= -1
			&& (conv->pad = '0'))
			conv->beg = conv->end - conv_ret;
		else
			conv->pad = ' ';
		while (conv->len < fmt->width && ++conv->len)
			add(sb, &conv->pad, 1);
		if (!is_flag('-', *fmt))
			trial(sb_slide(sb, conv->beg, conv->end));
	}
}

int	convert(t_strbuffer *sb, t_formatter *fmt, t_arglist *args)
{
	t_conversion	conv;
	int				ret;

	get_arg_at(fmt->pos, args);
	conv.beg = sb->length;
	ret = convert_without_width(sb, fmt, args);
	conv.end = sb->length;
	conv.len = conv.end - conv.beg;
	fill_width(sb, fmt, ret, &conv);
	return (ret);
}
