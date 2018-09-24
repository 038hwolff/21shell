/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 13:50:50 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/08 15:26:03 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (len);
}
