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
** SELECTION = fn + v 
** COPY = fn + y
** PASTE = fn + p
*/

char	*ft_termcaps(t_edl *edl, char *line, unsigned long key)
{
	size_t		len;
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	edl->col = ws.ws_col;
	len = ft_strlen(line);
	if (key == UP)
		history_umove(edl, &line);
	if (key == DOWN)
		history_dmove(edl, &line);
	if (key == LEFT || key == RIGHT || key == HOME || key == END)
		left_or_right(edl, key, len);
	if (key == UP_FN)
		prev_word(edl, line);
	if (key == DOWN_FN)
		next_word(edl, line, len);
	return (line);
}
