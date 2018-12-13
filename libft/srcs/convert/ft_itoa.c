/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:20:50 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/04 18:20:51 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	nbr;

	len = ft_nbrlen(n, 10);
	nbr = (unsigned int)n;
	if (n < 0)
	{
		nbr *= -1;
		++len;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = (char)((nbr % 10) + '0');
	while (nbr /= 10)
		s[--len] = (char)((nbr % 10) + '0');
	if (n < 0)
		*s = '-';
	return (s);
}
