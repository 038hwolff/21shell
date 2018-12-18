#include "shell.h"

char	*delete_char(int **index, char *line, int len)
{
	int	i;
	char	*ret;

	i = 0;
	try_m(ret = (char *)ft_memalloc(len * sizeof(char)));
	while (i < **index)
	{
		ret[i] = line[i];
		i++;
	}
	while (i < len - 1)
	{
		ret[i] = line[i + 1];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*control_d(char *line, int *index)
{
	char	*ret;
	int	len;
	t_data	*data;

	ret = NULL;
	data = get_data();
	data->eof = 1;
	len = (int)ft_strlen(line);
	if (len < 2)
		len = 2;
	if (ft_strcmp(line, "\0") == 0)
		exit (1);
	if (*index == len)
		return (line);
	ret = delete_char(&index, line, len);
	free(line);
	return (ret);
}
