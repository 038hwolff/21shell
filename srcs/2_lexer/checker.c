/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:10:16 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/06 21:15:32 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static const char *g_delim[20] = {"<<-", "<<", ">>", "<>", "<&", ">&", ">|",
	"&&", "||", ";;", "|", "&", ";", "<", ">", "(", ")", "\n", 0};

static const int g_type[20] = {DOUBLELESSDASH, DOUBLELESS, DOUBLEGREAT,
	LESSGREAT, LESSAND, GREATAND, GREATPIPE, DOUBLEAND, DOUBLEPIPE,
	DOUBLESEMICOLON, PIPE, AND, SEMICOLON, LESS, GREAT, OPEN_PAR, CLOSED_PAR,
	NEWLINE, 0};

static void
	check_for_io_number(t_token *token, char **line)
{
	int	len;
	int	is_after;

	len = 0;
	if ((is_after = (**line == '<' || **line == '>') && *(*line + 1) == '&'))
		*line += 2;
	discard_spaces_tabs(line);
	if (is_after && **line == '-')
		++len;
	else if (ft_isdigit(**line))
	{
		++len;
		while (ft_isdigit(*(*line + len)))
			++len;
	}
	if (len > 0)
	{
		try_m((token->val = ft_strsub(*line, 0, len)));
		token->length = len;
		token->type = IO_NUMBER;
		*line += len;
	}
}

static void
	check_operators(t_token *token, char **line)
{
	t_token	*io_number;
	size_t	len;
	int		i;

	i = -1;
	while (g_delim[++i])
	{
		if (ft_strnequ(*line, g_delim[i], (len = ft_strlen(g_delim[i]))))
		{
			try_m((token->val = ft_strsub(*line, 0, len)));
			token->type = g_type[i];
			token->length = len;
			if ((token->type == LESSAND || token->type == GREATAND))
			{
				io_number = token_new(NULL, 0, 0, NULL);
				check_for_io_number(io_number, line);
				if (!io_number->val)
					ft_memdel((void**)&io_number);
				token->next = io_number;
				return ;
			}
			*line += len;
			return ;
		}
	}
}

static void
	check_io_number(t_token *token, char **line)
{
	size_t len;

	if (ft_isdigit(**line))
	{
		len = 1;
		while (ft_isdigit(*(*line + len)))
			++len;
		if (*(*line + len) == '<' || *(*line + len) == '>')
		{
			try_m((token->val = ft_strsub(*line, 0, len)));
			token->type = IO_NUMBER;
			token->length = len;
			*line = *line + len;
		}
	}
}

t_token
	*get_delimitor_token(char **line)
{
	t_token *new;

	new = token_new(NULL, 0, 0, NULL);
	check_operators(new, line);
	check_io_number(new, line);
	if (!new->val)
		ft_memdel((void**)&new);
	return (new);
}
