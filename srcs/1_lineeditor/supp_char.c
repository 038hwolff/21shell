/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:24:15 by pespalie          #+#    #+#             */
/*   Updated: 2018/12/18 09:24:24 by pespalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*supp_char(char *line, int *index)
{
	char	*ret;
	int		len;
	int		i;

	if (*index == 0)
		return (line);
	len = ft_strlen(line);
	len < 2 ? len = 2 : 0;
	try_m(ret = (char *)ft_memalloc(sizeof(char) * len));
	i = -1;
	while (++i < *index - 1)
		ret[i] = line[i];
	while (i < len - 1)
	{
		ret[i] = line[i + 1];
		i++;
	}
	ret[i] = '\0';
	(*index)--;
	if (*line || line)
		free(line);
	return (ret);
}
