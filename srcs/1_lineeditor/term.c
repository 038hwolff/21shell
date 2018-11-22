#include "../../includes/shell.h"

/*
** HOME = FN + left arrow
** END = FN + right arrow
*/

//void	left_or_right(t_var *var, char *buf, size_t len)
void	left_or_right(t_var *var, unsigned long key, size_t len)
{
	if (key == LEFT && var->index > 0)
		mouve_left(var);
	if (key == RIGHT && var->index < (int)len)
		mouve_right(var);
	if (key == HOME)
	{
		while (var->index > 0)
			mouve_left(var);
	}
	if (key == END)
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

//char	*ft_termcaps(t_var *var, char *line, char *buf)
char	*ft_termcaps(t_var *var, char *line, unsigned long key)
{
	size_t		len;
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	var->col = ws.ws_col;
	len = ft_strlen(line);
	//(HAUT) ? history_umove(var, &line) : (0);
	if (key == UP)
		history_umove(var, &line);
//	(BAS) ? history_dmove(var, &line) : (0);
	if (key == DOWN)
		history_dmove(var, &line);
	if (key == LEFT || key == RIGHT || key == HOME || key == END)
		left_or_right(var, key, len);
	if (key == UP_FN)
		prev_word(var, line);
	if (key == DOWN_FN)
		next_word(var, line, len);
	return (line);
}
