/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:33:48 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 15:34:37 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

int				is_valid_entry(t_data *data, int z, int tot)
{
	int		res;

	if ((tot > 0 && data->entry[tot - 1] == '\n') || z == 0)
	{
		if (z == 0)
			ft_putchar('\n');
		if (!(res = is_quotes(data->entry)))
		{
			if (tot > (z ? 2 : 1) - 1 && data->entry[tot - (z ? 2 : 1)] == '\\')
				ft_putstr("> ");
			else
				return (1);
		}
		else
			put_quote_request(res);
	}
	return (0);
}
