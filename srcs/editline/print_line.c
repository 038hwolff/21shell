/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:40:09 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 17:40:12 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*insert_char(char *line, char buf[1000], int *index)
{
	int	len;
	char	*ret;
	int	i;

	len = ft_strlen(line) + ft_strlen(buf) - 1;
	ret = (char *)ft_memalloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < *index)
		ret[i] = line[i];
	(ft_strlen(buf) == 1) ? ret[i] = buf[0] : 0;
	while (++i <= len)
		ret[i] = line[i - ft_strlen(buf)];
	ret[i] = '\0';
	free(line);
	return (ret);
}

void	print_line(t_var *var, char **line, char buf[1000])
{ 
	//Gerer le multilignes

	*line = insert_char(*line, buf, &var->index);
	var->index++;
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 0), 2);
	ft_putstr_fd(tgetstr("cd", NULL), 2);
	display_prompt();
	ft_putstr_fd(*line, 2);
}
