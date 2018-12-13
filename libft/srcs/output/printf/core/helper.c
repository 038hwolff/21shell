/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:14:37 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/10 13:46:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_flag(char c, t_formatter fmt)
{
	return ((fmt.flags & (1 << ft_indexof(c, FLAGS))) > 0);
}

int		is_length(char c, t_formatter fmt, int v)
{
	return (fmt.length & (v << ft_indexof(c, LENGTHS)));
}

void	init_buffers(t_strbuffer *sb1, t_strbuffer *sb2)
{
	trial(sb_init(sb1));
	trial(sb_init(sb2));
}

void	init_args(t_arglist *args, va_list ap)
{
	va_copy(args->begin, ap);
	va_copy(args->natural, ap);
	va_copy(args->selected, ap);
}

void	get_arg_at(int pos, t_arglist *args)
{
	if (pos)
	{
		va_copy(args->selected, args->begin);
		while (--pos >= 1)
			va_arg(args->selected, void *);
	}
}
