/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 01:01:52 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/09 20:41:35 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vasprintf(char **ret, const char *format, va_list ap)
{
	const char	*next;
	t_strbuffer	all_buff;
	t_strbuffer	conv_buff;
	t_arglist	args;

	init_buffers(&all_buff, &conv_buff);
	init_args(&args, ap);
	while ((next = ft_strchr(format, '%')) && *next)
	{
		add(&conv_buff, format, next - format);
		if (handle_formatter(&conv_buff, &(next), &args, all_buff.length) == -1)
		{
			add(&all_buff, "", 1);
			*ret = all_buff.str;
			ft_strdel(&conv_buff.str);
			return (-1);
		}
		add(&all_buff, conv_buff.str, conv_buff.length);
		conv_buff.length = 0;
		format = next;
	}
	add(&all_buff, format, ft_strlen(format));
	*ret = all_buff.str;
	ft_strdel(&conv_buff.str);
	return (all_buff.length);
}
