#include "../includes/shell.h"

/*
** CUT = alt + d
*/

char	*cut_high(t_edl *edl, t_hist *hist, char *line)
{
	char	*new_line;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (int)ft_strlen(line))
	{
		if (edl->light[i] == 1)
			j++;
		i++;
	}
	try_m(hist->copy = (char *)ft_memalloc(j * sizeof(char)));
	hist->copy[j] = '\0';
	i = 0;
	j = 0;
	while (i < (int)ft_strlen(line))
	{
		if (edl->light[i] == 1)
		{
			hist->copy[j] = line[i];
			j++;
		}
		i++;
	}
	try_m(new_line = (char *)ft_memalloc(ft_strlen(line) - j * sizeof(char)));
	i =  0;
	j = 0;
	while (i < (int)ft_strlen(line))
	{
		if (edl->light[i] == 0)
		{
			new_line[j] = line[i];
			j++;
		}
		i++;
	}
	free(line);
	edl->multiline = edl->index / edl->col;
	clear_line(edl, new_line);
	j = (int)ft_strlen(new_line);
	while (--j >= edl->index)
		ft_putstr_fd(tgetstr("le", NULL), 1);
	return (new_line);
}
