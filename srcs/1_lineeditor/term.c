#include "../../includes/shell.h"

/*
** HOME = FN + left arrow
** END = FN + right arrow
*/

void	left_or_right(t_edl *edl, unsigned long key, size_t len)
{
	if (key == LEFT && edl->index > 0)
		mouve_left(edl);
	if (key == RIGHT && edl->index < (int)len)
		mouve_right(edl);
	if (key == HOME)
	{
		while (edl->index > 0)
			mouve_left(edl);
	}
	if (key == END)
	{
		while (edl->index < (int)len)
			mouve_right(edl);
	}
}

/*
** LINE_UP = maj + up arrow
** LINE_DOWN = maj + down arrow
*/

void	line_moves(t_edl *edl, char *line, unsigned long key)
{
	int	i;

	i = 0;
	if (key == LINE_UP && edl->multiline)
	{
		while (i < edl->col && edl->index > 0)
		{
			mouve_left(edl);
			i++;
		}
	}
	if (key == LINE_DOWN && (len_line(edl) / edl->col) > 0)
	{
		while (i < edl->col && edl->index < (int)ft_strlen(line))
		{
			mouve_right(edl);
			i++;
		}
	}
}

/*
** SELECTION = fn + v 
** COPY = fn + y
** PASTE = fn + p
*/

char	*ft_termcaps(t_edl *edl, char *line, unsigned long key, t_hist *hist)
{
	size_t		len;
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	edl->col = ws.ws_col;
	len = ft_strlen(line);
	if (key == UP)
		history_umove(edl, &line, hist);
	if (key == DOWN)
		history_umove(edl, &line, hist);
	if (key == LEFT || key == RIGHT || key == HOME || key == END)
		left_or_right(edl, key, len);
	if (key == UP_FN)
		prev_word(edl, line);
	if (key == DOWN_FN)
		next_word(edl, line, len);
	if (key == LINE_UP || key == LINE_DOWN)
		line_moves(edl, line, key);
	return (line);
}
