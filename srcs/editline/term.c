#include "../../includes/shell.h"

void	left_or_right(t_var *var, char *buf, size_t len)
{
	if (GAUCHE && var->index > 0)
		mouve_left(var);
	if (DROITE && var->index < (int)len)
		mouve_right(var);
}

/*
** COPY = ctrl + k
** PASTE = ctrl + i
*/

char	*ft_termcaps(t_var *var, char *line, char *buf)
{
	size_t	len;
	
	len = ft_strlen(line);
	(GAUCHE || DROITE) ? left_or_right(var, buf, len) : (0);
	(HAUT) ? line = history_umove(var) : (0);
	(BAS) ? line = history_dmove(var) : (0);
	return (line);
}
