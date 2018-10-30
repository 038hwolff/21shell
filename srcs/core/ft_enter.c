/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:40:28 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 17:44:39 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	ft_enter(char *line, t_var *var)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	data->args = ft_split(line);
	is_builtins(data);
	var->index = 0;
	return (0);
}
