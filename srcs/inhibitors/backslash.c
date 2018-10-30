/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 19:41:58 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 17:01:12 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int		manage_backslash(t_data *data, char **res, int *i)
{
	char	*tmp;
	char	*tmp2;

	tmp = *res;
	++(*i);
	if (!(tmp2 = ft_strsub(data->entry, *i, 1))
			|| !(*res = ft_strjoin(*res, tmp2)))
		return (0);
	free(tmp);
	free(tmp2);
	return (1);
}
