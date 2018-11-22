#include "../../includes/shell.h"

void	history_dmove(t_edl *edl, char **line)
{
	int j;

	if (edl->h_count == 0)
	{
		ft_putstr_fd(tgetstr("bl", NULL), 1);
		return ;
	}
	j = edl->h_current + 1;
	if (j >= edl->h_count)
	{
		ft_putstr_fd(tgetstr("bl", NULL), 1);
		return ;
	}
	while (edl->index > 0)
		mouve_left(edl);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 2), 1);
	ft_putstr_fd(tgetstr("ce", NULL), 1);
	ft_putstr_fd(edl->hist[j], 1);
	edl->h_current = j;
	free(*line);
	*line = ft_strdup(edl->hist[j]);
	edl->index = ft_strlen(*line);
	edl->multiline = (len_line(edl) + edl->index) / edl->col;
}

void	history_umove(t_edl *edl, char **line)
{
	int	j;

	j = 0;
	if (edl->h_current == 0)
		j = edl->h_count - 1;
	else
		j = edl->h_current - 1;
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
	ft_putstr_fd(edl->hist[j], 1);
	edl->h_current = j;
	free(*line);
	*line = ft_strdup(edl->hist[j]);
	edl->index = ft_strlen(*line);
	edl->multiline = (len_line(edl) + edl->index) / edl->col;
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

char	**ft_realloc(t_edl *edl, char *value)
{
	int		i;
	char	**new_env;

	new_env = (char **)ft_memalloc(sizeof(char *) * (edl->h_count + 2));
	new_env[edl->h_count + 1] = NULL;
	i = 0;
	while (i < edl->h_count)
	{
		new_env[i] = ft_strdup(edl->hist[i]);
		i++;
	}
	new_env[i] = ft_strdup(value);
	free_cases(edl->hist);
	return (new_env);
}

char	**add_history(t_edl *edl, char *value)
{
	if (edl->h_count == 0)
		edl->hist[0] = ft_strdup(value);
	else
		edl->hist = ft_realloc(edl, value);
	edl->h_count++;
	return (edl->hist);
}
