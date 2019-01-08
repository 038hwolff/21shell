/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:44:27 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/08 21:26:29 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*insert_end(char *line, char *value, t_edl *edl)
{
	char	*ret;

	try_m(ret = ft_strjoin(line, value));
	if (edl->light)
		ft_memdel((void **)&edl->light);
	try_m(edl->light = (int *)ft_memalloc(((int)ft_strlen(ret) + 1)
		* sizeof(int)));
	if (*line || line)
		ft_strdel(&line);
	edl->c_light = 0;
	return (ret);
}

char	*create_ret(int *index, char *value, size_t len, char *line)
{
	char	*ret;
	int		i;

	ret = NULL;
	try_m(ret = (char *)ft_memalloc(sizeof(char) * (len + 1)));
	i = 0;
	while (i < *index)
	{
		ret[i] = line[i];
		++i;
	}
	if (ft_strlen(value) == 1)
		ret[i++] = value[0];
	while (i < (int)len)
	{
		ret[i] = line[i - ft_strlen(value)];
		++i;
	}
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
	value = (char *)&key;
	len = ft_strlen(line);
	i = -1;
	len = ft_strlen(line) + ft_strlen(value);
	if (*index == (int)len)
		return (insert_end(line, value, edl));
	ret = NULL;
	ret = create_ret(index, value, len, line);
	if (edl->light)
		ft_memdel((void **)&edl->light);
	try_m(edl->light = (int *)ft_memalloc(((int)ft_strlen(ret) + 1)
		* sizeof(int)));
	edl->c_light = 0;
	if (*line || line)
		ft_strdel(&line);
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
	while (++j <= (ft_strlen(edl->line) + edl->prompt_len + len))
		write(1, "\b", 1);
	display_prompt(edl);
	ft_putstr_fd(*line, 1);
	edl->multiline = get_cursor_line(edl, edl->index, *line);
	c = ft_strlen(*line);
	while (--c >= edl->index)
		ft_putstr_fd(tgetstr("le", NULL), 1);
}

void	print_line(t_data *data, char **line, unsigned long key)
{
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	data->edl.col = ws.ws_col;
	if (key == TABU)
		*line = complete_word(data, *line);
	if (key != SUPP && key != DELETE && key != CTRLD && key != TABU)
		*line = insert_char(*line, key, &data->edl.index, &data->edl);
	if (key == SUPP || (key == DELETE && ++data->edl.index))
		*line = supp_char(*line, &data->edl.index);
	if (key == CTRLD)
		*line = control_d(*line, &data->edl.index);
	if (key != SUPP && key != DELETE && key != CTRLD && key != TABU)
		data->edl.index++;
	reprint_line(key, &data->edl, line);
}
