
#include "shell.h"

/*
** interception de signaux pour ne rien faire
*/

void	init_sig(void)
{
	int	i;

	i = 1;
	//while (i < 32)
	//	signal(i++, SIG_IGN);
	//signal(SIGTERM, SIG_DFL);
	//signal(SIGINT, SIG_DFL);
}

int		check_if_sigint(t_data *data, char **line)
{
	if (line && *line
		&& data->sigint == 1)
	{
		ft_strdel(&data->edl.line);
		try_m(data->edl.line = ft_strdup(*line));
		ft_strdel(line);
		return (1);
	}
	return (0);
}
