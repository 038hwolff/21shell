/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:25:38 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/18 14:02:29 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Pattern singleton pour récupérer la structure de données du shell
*/

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
		try_m(data = (t_data*)ft_memalloc(sizeof(t_data)));
	return (data);
}
