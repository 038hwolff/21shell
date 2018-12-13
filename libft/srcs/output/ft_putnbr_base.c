/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:14:54 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/09 16:14:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_error(char *base)
{
	if (ft_strlen(base) < 2 || !ft_hasnodupl(base))
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-' || *base < ' ' || *base > '~')
			return (0);
		++base;
	}
	return (1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	base_len;

	if (ft_check_error(base))
	{
		n = nbr;
		if (nbr < 0)
		{
			n *= -1;
			ft_putchar('-');
		}
		base_len = ft_strlen(base);
		if (n / base_len)
			ft_putnbr_base(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
}
