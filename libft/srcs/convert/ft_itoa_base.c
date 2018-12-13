/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_str_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:14:34 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/09 16:32:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, char *base)
{
	char			*s;
	size_t			len;
	size_t			base_len;
	unsigned int	nbr;

	base_len = ft_strlen(base);
	nbr = (n < 0 ? (unsigned int)-n : (unsigned int)n);
	len = ft_nbrlen(n, base_len);
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = base[nbr % base_len];
	while (nbr /= base_len)
		s[--len] = base[nbr % base_len];
	if (n < 0)
		*s = '-';
	return (s);
}
