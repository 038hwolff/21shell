# include "../../includes/shell.h"

/*
** FN + up arrow
*/

void	prev_word(t_edl *edl, char *line)
{
	while (edl->index > 0 && !ft_isspace_wnt(line[edl->index]))
		mouve_left(edl);
	while (edl->index > 0 && ft_isspace_wnt(line[edl->index]))
		mouve_left(edl);
	while (edl->index > 0 && !ft_isspace_wnt(line[edl->index]))
		mouve_left(edl);
	if (edl->index > 0)
		mouve_right(edl);
}

/*
** FN + down arrow
*/

void	next_word(t_edl *edl, char *line, size_t len)
{
	while (edl->index < (int)len && !ft_isspace_wnt(line[edl->index]))
		mouve_right(edl);
	while (edl->index < (int)len && ft_isspace_wnt(line[edl->index]))
		mouve_right(edl);
}

void	mouve_left(t_edl *edl)
{
	edl->index--;
	ft_putstr_fd(tgetstr("le", NULL), 1);
	if (len_line(edl) % edl->col == 0)
		edl->multiline--;
}

void	mouve_right(t_edl *edl)
{
	edl->index++;
	if (len_line(edl) % edl->col == 0)
	{
		ft_putstr_fd(tgetstr("do", NULL), 1);
		ft_putstr_fd(tgetstr("ch", NULL), 1);
		edl->multiline++;

	}
	else
		ft_putstr_fd(tgetstr("nd", NULL), 1);
}
