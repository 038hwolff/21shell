/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:06:21 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/09 15:06:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int				len;

	len = ft_strlen(src);
	while (*src && size-- > 1)
		*(dst++) = *(src++);
	if ((int)size >= 0)
		*dst = 0;
	return (len);
}
