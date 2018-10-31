/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabncpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:15:19 by hben-yah          #+#    #+#             */
/*   Updated: 2018/09/19 11:24:53 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabncpy(char **dst, char **src, size_t size)
{
	char **d;

	d = dst;
	while (*src && size--)
		*(d++) = *(src++);
	if ((int)size > 0)
		while (size--)
			*(d++) = NULL;
	return (dst);
}
