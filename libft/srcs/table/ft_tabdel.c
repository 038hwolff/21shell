/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:34:52 by hben-yah          #+#    #+#             */
/*   Updated: 2018/09/19 19:27:18 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_tabdel(void ***ap)
{
	char **p;

	if (ap && *ap)
	{
		p = (char **)*ap;
		while (*p)
			ft_strdel(p++);
		free(*ap);
		*ap = NULL;
	}
}
