#include "shell.h"

int			exp_tilde(char **str, t_data *data)
{
	char		*tmp;
	char		*home;

	if ((*str)[0] == '~' && ((*str)[1] == '/' || !(*str)[1]))
	{
		if ((home = env_get(data->env, "HOME")))
		{
			tmp = *str;
			(*str) = ft_3strjoinfree(home, 0, &tmp[1], 0);
			free(tmp);
		}
	}
	return (1);
}
