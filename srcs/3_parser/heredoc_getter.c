/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/11 20:51:21 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int
	check_heredoc_cancel(t_data *data, char **line)
{
	if (check_if_sigint(data, line))
		return (1);
	if (data->eof)
	{
		ft_putchar('\n');
		data->eof = 0;
		return (2);
	}
	return (0);
}

static int
	check_heredoc_sigint_and_eof(t_data *data, char **line, char **copy)
{
	if (check_if_sigint(data, line))
	{
		ft_strdel(&data->edl.line);
		data->edl.line = *copy;
		return (1);
	}
	if (data->eof)
	{
		ft_putchar('\n');
		ft_strdel(copy);
		data->eof = 0;
		return (2);
	}
	return (0);
}

static int
	handle_heredoc_backslash(t_data *data, char **line, size_t *len)
{
	char	*tmp1;
	char	*tmp2;
	int		ret;

	while ((*len = ft_strlen(*line)) > 1
			&& (*line)[*len - 2] == '\\')
	{
		data->incomp_type = INC_BKSLASH;
		set_special_prompt(data);
		*len = pop_backslashed_nl(line);
		try_m((tmp1 = ft_strdup(data->edl.line)));
		read_line();
		try_m((tmp2 = ft_strdup(data->edl.line)));
		ft_strdel(&data->edl.line);
		data->edl.line = tmp1;
		tmp1 = NULL;
		if ((ret = check_heredoc_sigint_and_eof(data, line, &tmp2)))
			return (ret);
		tmp1 = *line;
		try_m((*line = ft_strjoin(tmp1, tmp2)));
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
	return (0);
}

static int
	handle_heredoc_line(t_data *data, t_token *token, int quoted)
{
	char	*tmp;
	size_t	len;

	if ((len = check_heredoc_cancel(data, &data->edl.line)))
		return (len);
	if ((len = 0) || !quoted)
		if (handle_heredoc_backslash(data, &data->edl.line, &len) == 1)
			return (1);
	data->incomp_type = COMPLETE;
	set_special_prompt(data);
	len = ft_strlen(token->next->val);
	if (ft_strnequ(data->edl.line, token->next->val, len - 1))
		return (2);
	tmp = token->heredoc;
	if (tmp)
	{
		try_m((token->heredoc = ft_strjoin(tmp, data->edl.line)));
		ft_strdel(&tmp);
	}
	else
		try_m((token->heredoc = ft_strdup(data->edl.line)));
	return (0);
}

int
	get_heredoc_lines(t_data *data, t_token *token, int quoted)
{
	int		ret;

	try_m((token->heredoc = ft_strnew(0)));
	if (data->oneshot)
		return (1);
	while (1)
	{
		data->incomp_type = INC_HEREDOC;
		set_special_prompt(data);
		read_line();
		data->incomp_type = COMPLETE;
		set_special_prompt(data);
		if ((ret = handle_heredoc_line(data, token, quoted)) == 1)
			return (0);
		else if (ret == 2)
			break ;
	}
	return (1);
}
