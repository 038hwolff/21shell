#include "../../includes/shell.h"

char	*history_dmove(t_var *var)
{
	int j;

	j = var->h_current + 1;
	if (j > var->h_count)
	{
		ft_putstr_fd(tgetstr("bl", NULL), 2);
		return (NULL);
	}
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 2), 2);
	ft_putstr_fd(tgetstr("ce", NULL), 2);
	ft_putstr_fd(var->hist[j], 2);
	var->h_current = j;
	var->index = ft_strlen(var->hist[j]);
	return (var->hist[j]);
}

char	*history_umove(t_var *var)
{
	int	j;

	j = 0;
	if (var->h_current == 0)
		j = var->h_count - 1;
	else
		j = var->h_current - 1;
	if (j < 0)
	{
		ft_putstr_fd(tgetstr("bl", NULL), 2);
		return (NULL);
	}
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 2), 2);
	ft_putstr_fd(tgetstr("ce", NULL), 2);
	ft_putstr_fd(var->hist[j], 2);
	var->h_current = j;
	var->index = ft_strlen(var->hist[j]);
	return (var->hist[j]);
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
