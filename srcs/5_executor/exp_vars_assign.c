#include "shell.h"

char	*exp_assign(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)val;
	if (!env_set(&exp->data->env, key, word, 0))
		ft_putendl_fd("Failed to add vars to local", 2);
	return (ft_strdup(word));
}

char	*exp_unhandle(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)exp;
	(void)key;
	(void)val;
	(void)word;
	ft_putendl_fd("shell expansion:: unhandle operator", 2);
	return (0);
}
