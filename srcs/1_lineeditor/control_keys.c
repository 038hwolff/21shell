# include "../../includes/shell.h"

char	*control_d(char *line, int *index)
{
	char	*ret;
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(line);
	if (len < 2)
		len = 2;
	if (ft_strcmp(line, "\0") == 0)
		exit (1);
	if (*index == len)
		return (line);
	try_m(ret = (char *)ft_memalloc(len * sizeof(char)));
	while (i < *index)
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
	free(line);
	return (ret);
}
