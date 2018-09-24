/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:09:05 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/09 20:41:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		handle_formatter(t_strbuffer *sb, char const **s, t_arglist *args,
															int prev_len)
{
	t_formatter	fmt;
	int			ret;

	parse_formatter(s, &fmt, args);
	fmt.prev_len = prev_len;
	ret = 0;
	if (fmt.converter && (ret = convert(sb, &fmt, args)) == -1)
		return (-1);
	return (ret);
}
