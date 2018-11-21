# include "../../includes/shell.h"

/*
** FN + up arrow
*/

void	prev_word(t_var *var, char *line)
{
	while (var->index > 0 && !ft_isspace_wnt(line[var->index]))
		mouve_left(var);
	while (var->index > 0 && ft_isspace_wnt(line[var->index]))
		mouve_left(var);
	while (var->index > 0 && !ft_isspace_wnt(line[var->index]))
		mouve_left(var);
	if (var->index > 0)
		mouve_right(var);
}

/*
** FN + down arrow
*/

void	next_word(t_var *var, char *line, size_t len)
{
	while (var->index < (int)len && !ft_isspace_wnt(line[var->index]))
		mouve_right(var);
	while (var->index < (int)len && ft_isspace_wnt(line[var->index]))
		mouve_right(var);
}

void	mouve_left(t_var *var)
{
	var->index--;
	ft_putstr_fd(tgetstr("le", NULL), 1);
	if (len_line(var) % var->col == 0)
		var->multiline--;
}

void	mouve_right(t_var *var)
{
	var->index++;
	if (len_line(var) % var->col == 0)
	{
		ft_putstr_fd(tgetstr("do", NULL), 1);
		ft_putstr_fd(tgetstr("ch", NULL), 1);
		var->multiline++;

	}
	else
		ft_putstr_fd(tgetstr("nd", NULL), 1);
}
