/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:15:30 by hben-yah          #+#    #+#             */
/*   Updated: 2018/09/19 19:06:32 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabdup(char **tab)
{
	char	**dup;
	char	**ddup;

	if (!tab)
		return (NULL);
	if (!(dup = (char **)ft_memalloc(sizeof(char *) * (ft_strtablen(tab) + 1))))
		return (NULL);
	ddup = dup;
	while (*tab)
		if (!(*(ddup++) = ft_strdup(*(tab++))))
			return (NULL);
	*ddup = NULL;
	return (dup);
}
