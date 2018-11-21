#include "../../includes/shell.h"

void	history_dmove(t_var *var, char **line)
{
	int j;

	if (var->h_count == 0)
	{
		ft_putstr_fd(tgetstr("bl", NULL), 1);
		return ;
	}
	j = var->h_current + 1;
	if (j >= var->h_count)
	{
		ft_putstr_fd(tgetstr("bl", NULL), 1);
		return ;
	}
	while (var->index > 0)
		mouve_left(var);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 2), 1);
	ft_putstr_fd(tgetstr("ce", NULL), 1);
	ft_putstr_fd(var->hist[j], 1);
	var->h_current = j;
	free(*line);
	*line = ft_strdup(var->hist[j]);
	var->index = ft_strlen(*line);
	var->multiline = (len_line(var) + var->index) / var->col;
}

void	history_umove(t_var *var, char **line)
{
	int	j;

	j = 0;
	if (var->h_current == 0)
		j = var->h_count - 1;
	else
		j = var->h_current - 1;
	if (j < 0)
	{
		ft_putstr_fd(tgetstr("bl", NULL), 1);
		return ;
	}
	while (var->index > 0)
		mouve_left(var);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 2), 1);
	ft_putstr_fd(tgetstr("ce", NULL), 1);
	ft_putstr_fd(var->hist[j], 1);
	var->h_current = j;
	free(*line);
	*line = ft_strdup(var->hist[j]);
	var->index = ft_strlen(*line);
	var->multiline = (len_line(var) + var->index) / var->col;
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

char	**ft_realloc(t_var *var, char *value)
{
	int		i;
	char	**new_env;

	new_env = (char **)ft_memalloc(sizeof(char *) * (var->h_count + 2));
	new_env[var->h_count + 1] = NULL;
	i = 0;
	while (i < var->h_count)
	{
		new_env[i] = ft_strdup(var->hist[i]);
		i++;
	}
	new_env[i] = ft_strdup(value);
	free_cases(var->hist);
	return (new_env);
}

char	**add_history(t_var *var, char *value)
{
	if (var->h_count == 0)
		var->hist[0] = ft_strdup(value);
	else
		var->hist = ft_realloc(var, value);
	var->h_count++;
	return (var->hist);
}
