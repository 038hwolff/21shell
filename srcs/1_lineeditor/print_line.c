#include "../../includes/shell.h"

char	*supp_char(char *line, int *index)
{
	char	*ret;
	int	len;
	int	i;

	if (*index == 0)
		return (line);
	len = ft_strlen(line);
	len < 2 ? len = 2 : 0;
	ret = (char *)ft_memalloc(sizeof(char) * len);
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

char	*insert_end(char *line, char *value)
{
	char *ret;

	ret = ft_strjoin(line, value);
	free(line);
	return (ret);
}

char	*insert_char(char *line, unsigned long key, int *index)
{
	int	len;
	char	*ret;
	char	*value = NULL;
	int	i;


	value = (char *)(&key);
	len = ft_strlen(line);
	i = -1;
	if (*index == len && ft_strlen(value) >= 1)
		*index = *index + ft_strlen(value) - 1;
	len = ft_strlen(line) + ft_strlen(value) - 1;
	if (len == *index)
		return (insert_end(line, value));
	ret = (char *)ft_memalloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < *index)
		ret[i] = line[i];
	(ft_strlen(value) == 1) ? ret[i] = value[0] : 0;
	while (++i <= len)
		ret[i] = line[i - ft_strlen(value)];
	ret[i] = '\0';
	free(line);
	return (ret);
}

void	count_line(t_edl *edl, unsigned long key)
{
	if ((len_line(edl) % edl->col == 0) && key != SUPP)
		edl->multiline++;
	if ((len_line(edl) % edl->col == 0) && key == SUPP)
		edl->multiline--;
}

void	print_line(t_edl *edl, char **line, unsigned long key)
{
	struct winsize	ws;
	int		j;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	edl->col = ws.ws_col;
	if (key == TAB && edl->index == 0)
		key = SPACE;
	else if (key == TAB)
		return ;
	if (key != SUPP)
		*line = insert_char(*line, key, &edl->index);
	if (key == SUPP)
		*line = supp_char(*line, &edl->index);
	if (key != SUPP)
		edl->index++;
	j = -1;
	if (key == SUPP)
	{
		while (++j < edl->multiline)
			ft_putstr_fd(tgoto(tgetstr("up", NULL), 0, 0), 1);
	}
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 0), 1);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	while (++j <= (len_line(edl) + (int)ft_strlen(*line)))
		write(1, "\b", 1);
	display_prompt();
	ft_putstr_fd(*line, 1);
	count_line(edl, key);
	j = ft_strlen(*line);
	while (--j >= edl->index)
		ft_putstr_fd(tgetstr("le", NULL), 1);
}
