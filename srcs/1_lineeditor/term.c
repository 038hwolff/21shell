#include "../../includes/shell.h"

/*
** HOME = FN + left arrow
** END = FN + right arrow
*/

void	left_or_right(t_var *var, char *buf, size_t len)
{
	if (GAUCHE && var->index > 0)
		mouve_left(var);
	if (DROITE && var->index < (int)len)
		mouve_right(var);
	if (HOME)
	{
		while (var->index > 0)
			mouve_left(var);
	}
	if (END)
	{
		while (var->index < (int)len)
			mouve_right(var);
	}
}

/*
** SELECTION = fn + v 
** COPY = fn + y
** PASTE = fn + p
*/

char	*ft_termcaps(t_var *var, char *line, char *buf)
{
	size_t		len;
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	var->col = ws.ws_col;
	len = ft_strlen(line);
	(HAUT) ? history_umove(var, &line) : (0);
	(BAS) ? history_dmove(var, &line) : (0);
	(GAUCHE || DROITE || HOME || END) ? left_or_right(var, buf, len) : (0);
	(UP) ? prev_word(var, line) : (0);
	(DOWN) ? next_word(var, line, len) : (0);
	return (line);
}
