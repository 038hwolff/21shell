#include "shell.h"

int		check_cancel(t_data *data, char **line)
{
	if (check_if_sigint(data, line))
		return (1);
	if (check_eof(data))
	{
		eof_exception();
		ft_strdel(line);
		return (1);
	}
	return (0);
}
