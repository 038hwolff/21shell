/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:17:27 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/16 13:11:30 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			cd_free(char **tmp, t_data *ndata)
{
	free_tab(&ndata->env);
	free_tab(&ndata->args);
	free_tab(&tmp);
}

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

void		free_tab_content(char ***table)
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
