#include "shell.h"

/*
** COPY = alt + c
*/

void		copy_high(t_edl *edl, t_hist *hist, char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < (int)ft_strlen(line))
	{
		if (edl->light[i] == 1)
			j++;
		i++;
	}
	try_m(hist->copy = (char *)ft_memalloc(j * sizeof(char) + 1));
	hist->copy[j] = '\0';
	j = 0;
	i = 0;
	while (i < (int)ft_strlen(line))
	{
		if (edl->light[i] == 1)
		{
			hist->copy[j] = line[i];
			j++;
		}
		i++;
	}
}

void		clear_line(t_edl *edl, char *n_line)
{
	int	i;
	t_data	*data;

	i = -1;
	data = get_data();
	while (++i < edl->multiline)
		ft_putstr_fd(tgoto(tgetstr("up", NULL), 0, 0), 1);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 0), 1);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	display_prompt(data->prompt);
	ft_putstr_fd(n_line, 1);
}

/*
** PASTE = alt + p
*/

char		*paste_char(t_edl *edl, t_hist *hist, char *line)
{
	char		*new_line;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	try_m(new_line = (char *)ft_memalloc(ft_strlen(line) + ft_strlen(hist->copy) + 1));
	while (i < edl->index)
	{
		new_line[i] = line[l];
		i++;
		l++;
	}
	while (hist->copy[j])
	{
		new_line[i] = hist->copy[j];
		i++;
		j++;
		edl->index++;
	}
	while (line[l])
	{
		new_line[i] = line[l];
		i++;
		l++;
	}
	new_line[i] = '\0';
	ft_putstr_fd(tgetstr("se", NULL), 1);
	free(line);
	clear_line(edl, new_line);
	i = ft_strlen(new_line);
	while (--i >= edl->index)
		ft_putstr_fd(tgetstr("le", NULL), 1);
	if (edl->index < (int)ft_strlen(new_line))
		edl->multiline = (edl->index + 2) / edl->col;
	else
		edl->multiline = ((int)ft_strlen(new_line) + 2) / edl->col;
	try_m(edl->light = (int *)ft_memalloc(ft_strlen(new_line) * sizeof(int)));
	return (new_line);
}
