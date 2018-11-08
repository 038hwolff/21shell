#include "../../includes/shell.h"

char	*del_char(char *line, int *index)
{
	char	*ret;
	int	len;
	int	i;

	if (*index == 0)
		return (line);
	len = ft_strlen(line);
	len < 2 ? len = 2 : 0;
	ret = (char *)malloc(sizeof(char) * len);
	i = 0;
	while (i < *index - 1)
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
	(*index)--;
	free(line);
	return (ret);
}

char	*insert_char(char *line, char buf[1000], int *index)
{
	int	len;
	char	*ret;
	int	i;

	len = ft_strlen(line) + ft_strlen(buf) - 1;
	ret = (char *)ft_memalloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < *index)
		ret[i] = line[i];
	(ft_strlen(buf) == 1) ? ret[i] = buf[0] : 0;
	while (++i <= len)
		ret[i] = line[i - ft_strlen(buf)];
	ret[i] = '\0';
	free(line);
	return (ret);
}

void	print_line(t_var *var, char **line, char buf[1000])
{ 
	//Gerer le multilignes

	(!SUPP || !DEL) ? *line = insert_char(*line, buf, &var->index) : (0);
	(SUPP) ? *line = del_char(*line, &var->index) : (0);
	(!SUPP) ? var->index++ : (0);
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 0), 2);
	ft_putstr_fd(tgetstr("cd", NULL), 2);
	display_prompt();
	ft_putstr_fd(*line, 2);
}
