/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:52:52 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/03 17:52:54 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			d_len;
	size_t			s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size > d_len + 1)
		ft_strncat(dst, src, size - d_len - 1);
	return (s_len + (d_len >= size ? size : d_len));
}
