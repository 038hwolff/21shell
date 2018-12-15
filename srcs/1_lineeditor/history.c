#include "shell.h"

void	history_dmove(t_edl *edl, char **line, t_hist *hist)
{
	int j;

	if (hist->h_count == 0)
	{
		ft_putstr_fd(tgetstr("bl", NULL), 1);
		return ;
	}
	j = hist->h_current + 1;
	if (j >= hist->h_count)
	{
		ft_putstr_fd(tgetstr("bl", NULL), 1);
		return ;
	}
	while (edl->index > 0)
		mouve_left(edl);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 2), 1);
	ft_putstr_fd(tgetstr("ce", NULL), 1);
	ft_putstr_fd(hist->list[j], 1);
	hist->h_current = j;
	free(*line);
	try_m(*line = ft_strdup(hist->list[j]));
	edl->index = ft_strlen(*line);
	edl->multiline = edl->index / edl->col;
}

void	history_umove(t_edl *edl, char **line, t_hist *hist)
{
	int	j;

	j = 0;
	if (hist->h_current == 0)
		j = hist->h_count - 1;
	else
		j = hist->h_current - 1;
	if (j < 0)
	{
		ft_putstr_fd(tgetstr("bl", NULL), 1);
		return ;
	}
	while (edl->index > 0)
		mouve_left(edl);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 2), 1);
	ft_putstr_fd(tgetstr("ce", NULL), 1);
	ft_putstr_fd(hist->list[j], 1);
	hist->h_current = j;
	free(*line);
	try_m(*line = ft_strdup(hist->list[j]));
	edl->index = ft_strlen(*line);
	edl->multiline = edl->index / edl->col;
}

char	**free_cases(char **value)
{
	int i;

	i = 0;
	while (value[i])
	{
		free(value[i]);
		value[i] = NULL;
		i++;
	}
	free(value);
	value = NULL;
	return (value);
}

char	**ft_realloc(t_hist *hist, char *value)
{
	int		i;
	char	**new_env;

	try_m(new_env = (char **)ft_memalloc(sizeof(char *) * (hist->h_count + 2)));
	new_env[hist->h_count + 1] = NULL;
	i = 0;
	while (i < hist->h_count)
	{
		try_m(new_env[i] = ft_strdup(hist->list[i]));
		i++;
	}
	try_m(new_env[i] = ft_strdup(value));
	free_cases(hist->list);
	return (new_env);
}

char	**add_history(char *value, t_hist *hist)
{
	if (hist->h_count == 0)
		try_m(hist->list[0] = ft_strdup(value));
	else
		hist->list = ft_realloc(hist, value);
	hist->h_count++;
	return (hist->list);
}
