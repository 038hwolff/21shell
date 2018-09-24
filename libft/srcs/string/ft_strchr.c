/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:52:41 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/03 17:52:43 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char chara;

	chara = (char)c;
	while (*s)
	{
		if ((char)*s == chara)
			return ((char *)s);
		s++;
	}
	return (chara == 0 ? (char *)s : NULL);
}
