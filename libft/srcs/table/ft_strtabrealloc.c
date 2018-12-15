/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabrealloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:19:24 by hben-yah          #+#    #+#             */
/*   Updated: 2018/09/20 12:02:56 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabrealloc(char ***tab, size_t size)
{
	char	**tmp;

	tmp = ft_strtabnew(size);
	ft_strtabncpy(tmp, *tab, size);
	tmp[size] = NULL;
	free(*tab);
	*tab = tmp;
	return (*tab);
}
