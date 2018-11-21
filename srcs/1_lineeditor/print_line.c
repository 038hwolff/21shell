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

char	*insert_end(char *line, char buf[1000])
{
	char *ret;

	ret = ft_strjoin(line, buf);
	free(line);
	return (ret);
}

char	*insert_char(char *line, char buf[1000], int *index)
{
	int	len;
	char	*ret;
	int	i;

	len = ft_strlen(line);
	i = -1;
	if (*index == len && ft_strlen(buf) >= 2)
		*index = *index + ft_strlen(buf) - 1;
	len = ft_strlen(line) + ft_strlen(buf) - 1;
	if (len == *index)
		return (insert_end(line, buf));
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

void	count_line(t_var *var, char buf[1000])
{
	if ((len_line(var) % var->col == 0) && (!DEL && !SUPP))
		var->multiline++;
	if ((len_line(var) % var->col == 0) && (DEL || SUPP))
		var->multiline--;
}

void	print_line(t_var *var, char **line, char buf[1000])
{
	struct winsize	ws;
	int		j;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	var->col = ws.ws_col;
	(!SUPP && !DEL) ? *line = insert_char(*line, buf, &var->index) : (0);
	(SUPP) ? *line = supp_char(*line, &var->index) : (0);
	(!DEL && !SUPP) ? var->index++ : (0);
	j = -1;
	if (SUPP)
	{
		while (++j < var->multiline)
			ft_putstr_fd(tgoto(tgetstr("up", NULL), 0, 0), 1);
	}
	ft_putstr_fd(tgoto(tgetstr("ch", NULL), 0, 0), 1);
	ft_putstr_fd(tgetstr("cd", NULL), 1);
	while (++j <= (len_line(var) + (int)ft_strlen(var->line)))
		write(1, "\b", 1);
	display_prompt();
	ft_putstr_fd(*line, 1);
	count_line(var, buf);
	j = ft_strlen(*line);
	while (--j >= var->index)
		ft_putstr_fd(tgetstr("le", NULL), 1);
}
