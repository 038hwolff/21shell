/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:17:27 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 15:22:34 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		free_tab(char ***table)
{
	int	f;

	if (table && *table)
	{
		f = 0;
		while ((*table)[f])
		{
			ft_strdel(&((*table)[f]));
			f++;
		}
		free(*table);
		*table = NULL;
	}
}

void		free_table_content(char ***table)
{
	int	f;

	if (table && *table)
	{
		f = 0;
		while ((*table)[f])
		{
			ft_strdel(&((*table)[f]));
			f++;
		}
	}
}
