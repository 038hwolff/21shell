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

/*
** "vs" = standout cursor
** "le" = String to move the cursor left one column.
*/

void	mouve_left(t_edl *edl)
{
	ft_putstr_fd(tgetstr("vs", NULL), 1);
	edl->index--;
	ft_putstr_fd(tgetstr("le", NULL), 1);
	if (len_line(edl) % edl->col == 0)
		edl->multiline--;
	ft_putstr_fd(tgetstr("ve", NULL), 1);
}

/*
** "nd" = String to move the cursor right one column.
** "do" = String of commands to move the cursor vertically down one line
*/

void	mouve_right(t_edl *edl)
{
	ft_putstr_fd(tgetstr("vs", NULL), 1);
	edl->index++;
	if ((edl->index + 2) % edl->col == 0)
	{
		ft_putstr_fd(tgetstr("do", NULL), 1);
		edl->multiline++;

	}
	else
		ft_putstr_fd(tgetstr("nd", NULL), 1);
	ft_putstr_fd(tgetstr("ve", NULL), 1);
}
