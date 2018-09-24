/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:53:19 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/03 17:53:21 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *d;

	d = dst;
	while (*src && len--)
	{
		*(d++) = *(src++);
	}
	if ((int)len > 0)
		while (len--)
			*(d++) = 0;
	return (dst);
}
