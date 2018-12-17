#include "shell.h"


int		exp_quotes(char **str)
{
	remove_quotes_and_backslash(str);
	return (1);
}
