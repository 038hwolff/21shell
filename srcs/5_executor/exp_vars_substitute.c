#include "shell.h"

char	*exp_sub_param(t_varsexp *exp, char *key, char *val, char *word)
{
	if(exp || key || word)
		;
	return (ft_strdup(val));
}

char	*exp_sub_word(t_varsexp *exp, char *key, char *val, char *word)
{
	if(exp || key || val)
		;
	return (ft_strdup(word));
}

char	*exp_sub_null(t_varsexp *exp, char *key, char *val, char *word)
{
	if(exp || key || word || val)
		;
	return (ft_strdup(""));
}

char	*exp_sub_error(t_varsexp *exp, char *key, char *val, char *word)
{
	if(exp || key || word || val)
		;
	write(2, "expansion error substitute\n", 39);
	return (0);
}
