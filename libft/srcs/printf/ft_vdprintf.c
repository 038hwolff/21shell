/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 01:03:16 by hben-yah          #+#    #+#             */
/*   Updated: 2018/07/31 01:03:42 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*str;
	int		ret;

	str = NULL;
	if ((ret = ft_vasprintf(&str, format, ap)) == -1)
		write(fd, str, ft_strlen(str));
	else
		write(fd, str, ret);
	ft_strdel(&str);
	return (ret);
}
