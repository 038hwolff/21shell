/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:44:27 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 13:38:08 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*insert_end(char *line, char *value, t_edl *edl)
{
	char	*ret;
	
	try_m(ret = ft_strjoin(line, value));
	if (edl->light)
		ft_memdel((void **)&edl->light);
	try_m(edl->light = (int *)ft_memalloc((int)ft_strlen(ret) * sizeof(int)));
	if (*line || line)
		free(line);
	edl->c_light = 0;
	return (ret);
}

char	*create_ret(int *index, char *value, size_t len, char *line)
{
	char	*ret;
	int		i;

	ret = NULL;
	try_m(ret = (char *)ft_memalloc(sizeof(char) * (len + 1)));
	i = -1;
	while (++i < *index)
		ret[i] = line[i];
	if (ft_strlen(value) == 1)
		ret[i] = value[0];
	while (++i <= (int)len)
		ret[i] = line[i - ft_strlen(value)];
	ret[i] = '\0';
	return (ret);
}

/*
** Remet edl->c_light à 0 : permet mode de vidéo inversé de copy et cut.
*/

char	*insert_char(char *line, unsigned long key, int *index, t_edl *edl)
{
	size_t	len;
	char	*ret;
	char	*value;
	int		i;

	value = NULL;
	value = (char *)(&key);
	len = ft_strlen(line);
	i = -1;
	if (*index == (int)len && ft_strlen(value) >= 1)
		*index = *index + ft_strlen(value) - 1;
	len = ft_strlen(line) + ft_strlen(value) - 1;
	if (*index == (int)len)
		return (insert_end(line, value, edl));
	ret = NULL;
	ret = create_ret(index, value, len, line);
	if (edl->light)
		ft_memdel((void **)&edl->light);
	try_m(edl->light = (int *)ft_memalloc(((int)ft_strlen(ret)) * sizeof(int)));
	edl->c_light = 0;
	if (*line || line)
		free(line);
	return (ret);
}

void	reprint_line(unsigned long key, t_edl *edl, char **line)
{
	t_data		*data;
	int			c;
	size_t		j;
	size_t		len;

	data = get_data();
	c = -1;
	if (key == SUPP)
	{
		while (++c < edl->multiline)
			ft_putstr_fd(tgoto(tgetstr("up", NULL), 0, 0), 1);
	}
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 0), 1);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	j = -1;
	len = ft_strlen(*line);
	while (++j <= (len_line(edl) + len))
		write(1, "\b", 1);
	display_prompt(data->prompt);
	ft_putstr_fd(*line, 1);
	edl->multiline = edl->index / edl->col;
	c = ft_strlen(*line);
	while (--c >= edl->index)
		ft_putstr_fd(tgetstr("le", NULL), 1);
}

void	print_line(t_edl *edl, char **line, unsigned long key)
{
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	edl->col = ws.ws_col;
	if (key == TABU && edl->index == 0)
		key = SPACE;
	else if (key == TABU)
		return ;
	if (key != SUPP && key != CTRLD)
		*line = insert_char(*line, key, &edl->index, edl);
	if (key == SUPP)
		*line = supp_char(*line, &edl->index);
	if (key == CTRLD)
		*line = control_d(*line, &edl->index);
	if (key != SUPP && key != CTRLD)
		edl->index++;
	reprint_line(key, edl, line);
}
