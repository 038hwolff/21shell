/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/12 17:00:56 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int
	check_heredoc_cancel(t_data *data, char **line, char **delim)
{
	if (check_if_sigint(data, line) == 1)
	{
		ft_strdel(delim);
		return (1);
	}
	if (check_eof(data) || !*line)
		return (2);
	return (0);
}

static int
	check_heredoc_sigint_and_eof(t_data *data, char **line,
													char **word, char **copy)
{
	if (check_if_sigint(data, line))
	{
		ft_strdel(copy);
		ft_strdel(word);
		return (0);
	}
	if (check_eof(data))
	{
		eof_exception();
		ft_strdel(copy);
		ft_strdel(word);
		ft_strdel(line);
		return (0);
	}
	return (1);
}

static int
	handle_heredoc_backslash(t_data *data, char **line, char **word,
																	size_t *len)
{
	char	*tmp1;
	char	*tmp2;

	while ((*len = ft_strlen(*line)) > 1
			&& (*line)[*len - 1] == '\\')
	{
		data->incomp_type = INC_BKSLASH;
		set_special_prompt(data);
		*len = pop_backslashed_nl(line);
		try_m((tmp1 = ft_strdup(*line)));
		read_line();
		try_m((*line = ft_strdup(data->edl.line)));
		if (!check_heredoc_sigint_and_eof(data, line, word, &tmp1))
			return (0);
		tmp2 = *line;
		try_m((*line = ft_strjoin(tmp1, tmp2)));
		free(tmp1);
		free(tmp2);
	}
	return (1);
}

static int
	handle_heredoc_line(t_data *data, t_token *token, int quoted, char **delim)
{
	char	*tmp;
	char	*line;
	size_t	len;

	line = data->edl.line;
	if ((len = check_heredoc_cancel(data, &line, delim)))
		return (len);
	if ((len = 0) || !quoted)
		if (!handle_heredoc_backslash(data, &line, delim, &len))
			return (1);
	data->incomp_type = COMPLETE;
	set_special_prompt(data);
	line[len - 1] = 0;
	if (ft_strequ(line, token->next->val))
		return (2);
	tmp = token->heredoc;
	if (tmp)
	{
		try_m((token->heredoc = ft_strjoin(tmp, line)));
		ft_strdel(&tmp);
	}
	else
		try_m((token->heredoc = ft_strdup(line)));
	return (0);
}

int
	get_heredoc_lines(t_data *data, t_token *token, int quoted)
{
	int		ret;
	char	*delim;

	while (1)
	{
		data->incomp_type = INC_HEREDOC;
		set_special_prompt(data);
		read_line();
		data->incomp_type = COMPLETE;
		set_special_prompt(data);
		if ((ret = handle_heredoc_line(data, token, quoted, &delim)) == 1)
			return (0);
		else if (ret == 2)
			break ;
	}
	ft_strdel(&delim);
	return (1);
}
