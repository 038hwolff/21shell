/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:44:27 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/16 19:26:05 by hben-yah         ###   ########.fr       */
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

char	*insert_char(unsigned long key, t_edl *edl)
{
	size_t	len;
	char	*ret;
	char	*value;
	int		i;

	value = NULL;
	value = (char *)&key;
	len = ft_strlen(edl->line);
	i = -1;
	len = ft_strlen(edl->line) + ft_strlen(value);
	if (edl->index == (int)len)
		return (insert_end(edl->line, value, edl));
	ret = NULL;
	ret = create_ret(&edl->index, value, len, edl->line);
	if (edl->light)
		ft_memdel((void **)&edl->light);
	try_m(edl->light = (int *)ft_memalloc(((int)ft_strlen(ret) + 1)
		* sizeof(int)));
	edl->c_light = 0;
	if (edl->line)
		ft_strdel(&edl->line);
	return (ret);
}

void	reprint_line(t_data *data)
{
	int			c;
	size_t		j;

	c = -1;
	while (++c < data->edl.multiline)
		ft_putstr_fd(tgoto(tgetstr("up", NULL), 0, 0), 1);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 0), 1);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	j = -1;
	display_prompt(&data->edl);
	ft_putstr_fd(data->edl.line, 1);
	data->edl.multiline = get_cursor_line(&data->edl, data->edl.index, data->edl.line);
	move_cursor_to_index(&data->edl);
}

void	print_line(t_data *data, unsigned long key)
{
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	data->edl.col = ws.ws_col;
	if (key == TABU)
		data->edl.line = complete_word(data);
	if (key != SUPP && key != DELETE && key != CTRLD && key != TABU)
		data->edl.line = insert_char(key, &data->edl);
	if (key == SUPP || (key == DELETE && ++data->edl.index))
		data->edl.line = supp_char(&data->edl);
	if (key == CTRLD)
		data->edl.line = control_d(data);
	if (key != SUPP && key != DELETE && key != CTRLD && key != TABU)
		data->edl.index++;
	reprint_line(data);
}
