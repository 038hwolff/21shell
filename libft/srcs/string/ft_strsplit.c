/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:21:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/05/21 14:02:04 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wrdlen(const char *s, char c)
{
	const char *d;

	d = s;
	while (*d != c && *d)
		++d;
	return ((size_t)(d - s));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(res = (char **)ft_memalloc(sizeof(char *) * (ft_wrdcnt(s, c) + 1))))
		return (NULL);
	i = -1;
	while (*s)
	{
		if (*s != c)
		{
			if (i == -1 || *(s - 1) == c)
			{
				j = 0;
				if (!(res[++i] = ft_strnew(ft_wrdlen(s, c))))
					return (NULL);
			}
			res[i][j++] = *s;
		}
		++s;
	}
	res[i + 1] = 0;
	return (res);
}
