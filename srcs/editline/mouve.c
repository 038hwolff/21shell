# include "../../includes/shell.h"

//GERER LE SURLIGNEMENT DU CURRENT?
void	mouve_left(t_var *var)
{
	var->index--;
	ft_putstr_fd(tgetstr("le", NULL), 2);
}

void	mouve_right(t_var *var)
{
	var->index++;
	ft_putstr_fd(tgetstr("nd", NULL), 2);	
}
