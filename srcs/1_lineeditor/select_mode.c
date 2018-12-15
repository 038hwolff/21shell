#include "../../includes/shell.h"

/*
** Effectuer la selection avec la left arrow, effacer la selection avec right arrow
*/

static void	select_words(unsigned long key, t_edl *edl)
{
	if (key == LEFT && edl->index - 1 >= 0)
	{
		edl->index--;
		if (((edl->index + 2) % (edl->col - 1) == 0) && edl->light[edl->index] == 0)
		{
			edl->light[edl->index] = 1;
			edl->c_light++;
			ft_putstr_fd(tgetstr("so", NULL), 1);
			ft_putchar_fd(edl->line[edl->index], 1);
			write(1, "\b", 1);
		}
		else if (edl->light[edl->index] == 0)
		{
			edl->light[edl->index] = 1;
			edl->c_light++;
			ft_putstr_fd(tgetstr("so", NULL), 1);
			write(1, "\b", 1);
			ft_putchar_fd(edl->line[edl->index], 1);
		}
		ft_putstr_fd(tgetstr("le", NULL), 1);
	}
	if (key == RIGHT && edl->index < (int)ft_strlen(edl->line))
	{
		if (edl->light[edl->index] == 1)
		{
			edl->light[edl->index] = 0;
			edl->c_light--;
			ft_putstr_fd(tgetstr("se", NULL), 1);
			ft_putchar_fd(edl->line[edl->index], 1);
			write(1, "\b", 1);
		}
		edl->index++;
		if ((edl->index + 2) % edl->col == 0)
			ft_putstr_fd(tgetstr("do", NULL), 1);
		else
			ft_putstr_fd(tgetstr("nd", NULL), 1);
	}
}

/*
** SELECTION = alt + v
*/

void	select_mode(t_edl *edl, unsigned long key)
{
	unsigned long	key_2;

	while (key == SELECT)
	{
		key_2 = 0;
		if (edl->index >= 0 && edl->index < (int)ft_strlen(edl->line))
		{
			if (edl->light[edl->index] == 0)
			{
				edl->light[edl->index] = 1;
				edl->c_light++;
				ft_putstr_fd(tgetstr("so", NULL), 1);
				ft_putchar_fd(edl->line[edl->index], 1);
				write(1, "\b", 1);
			}
		}
		read(STDIN_FILENO, &key_2, 10);
		if (key_2 == UP_FN)
			prev_word(edl, edl->line);
		if (key_2 == DOWN_FN)
			next_word(edl, edl->line, ft_strlen(edl->line));
		if (key_2 == SELECT)
			return ;
		select_words(key_2, edl);
	}
}

