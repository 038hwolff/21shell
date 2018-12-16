#include "shell.h"

int			is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

void		exp_goto_next_quote(char **str)
{
	char	*ptr;
	char	quote_val;

	ptr = *str;
	quote_val = *ptr;
	ptr++;
	while (*ptr)
	{
		if (*ptr == '\\' && is_quote(*(ptr + 1)) && quote_val == '"')
			ft_strrmvchr(ptr);
		else if (*ptr == quote_val)
			break ;
		ptr++;
	}
	*str = ptr;
}
