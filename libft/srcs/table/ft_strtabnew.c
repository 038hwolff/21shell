/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:15:39 by hben-yah          #+#    #+#             */
/*   Updated: 2018/09/20 12:02:52 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabnew(size_t size)
{
	char **tab;

	if (!(tab = (char **)ft_memalloc(sizeof(char*) * (size + 1))))
		return (NULL);
	return (tab);
}
