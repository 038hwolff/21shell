/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/27 13:25:17 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** append_token_value :
** Ajoute au token précédent la partie de **line correspondant à la fin du
** token.
** Realloc **line en fonction.
*/

void	append_token_value(t_token *token, int i, char **line)
{
	char		*head;
	char		*tail;

	try_m((tail = ft_strsub(*line, 0, i)));
	try_m((token->val = ft_strjoin((head = token->val), tail)));
	token->length += i;
	ft_strdel(&head);
	ft_strdel(&tail);
	tail = *line;
	try_m((*line = ft_strdup(*line + i)));
	ft_strdel(&tail);
}

/*
** pop_char :
** Supprime les back-slash suivi de '\n' dans la chaine de char *s.
*/

int	pop_char(char **line, int i, char c)
{
	char	*tmp;
	int		diff;
	size_t	len;

	diff = (c == '\n' ? 2 : 1);
	len = ft_strlen(*line);
	tmp = *line;
	*line = ft_strnew(len - diff);
	ft_strncpy(*line, tmp, i);
	ft_strcpy(*line + i, tmp + (i + diff));
	ft_strdel(&tmp);
	return (c != '\n' ? i : --i);
}

int	pop_backslashed_nl(char **line)
{
	int		i;
	char *tmp;

	i = 0;
	while (*((*line) + i))
	{
		if (*((*line) + i) == '\'')
		{
			tmp = strquote(*line + i);
			i = tmp - *line;
			(*line)[i] && ++i;
		}
		else if (*((*line) + i) == '\\')
			i = pop_char(line, i, '\\');
		else
			++i;
	}
	return (i);
}


void merge_tokens(t_token *t1, t_token *t2)
{
	char *tmp;

	if (t1 && t2)
	{
		try_m((t1->val = ft_strjoin((tmp = t1->val), t2->val)));
		t1->length += t2->length;
		ft_strdel(&tmp);
		ft_strdel(&t2->val);
		t1->next = t2->next;
		ft_memdel((void**)&t2);
	}
}

/*
** complete_command_backslash :
** Suite à une inhibition du back-slash.
** Trouve la fin du token précédent et apelle le split.
*/

void	complete_command_backslash(t_token *token, char **line)
{
	if (!token || !line || !*line)
		return ;
	ft_printf("avant : %d\n", token->length);
	token->length = pop_backslashed_nl(&token->val);
	ft_printf("apres : %d\n", token->length);
	merge_tokens(token, get_next_token(line));
}



/*
** complete_command_quote :
** Suite à une inhibition des quotes.
** Trouve la fin du token précédent et apelle le split.
*/

void	complete_command_quote(t_token *token, char **line, char quotetype)
{
	int			len;

	if (!token || !line || !*line)
		return ;
	len = 0;
	while ((*line)[len])
	{
		if ((*line)[len] == '\\' && quotetype == '"')
			++len && (*line)[len] && ++len;
		else if ((*line)[len] == quotetype)
		{
			++len;
			break ;
		}
		else
			++len;
	}
	append_token_value(token, len, line);
	merge_tokens(token, get_next_token(line));
}

/*
int		token_value_length(int len, char *s)
{
	while (s[len] && s[len] != '\n' && !is_space_or_tab(s[len]) && !ft_is_op(s + len))
	{
		if (s[len] == '\\')
			++len;
		else if (s[len] == '\'')
			len = strquote(len, s);
		else if (s[len] == '"')
			len = strdquote(len, s);
		s[len] && ++len;
	}
	return (len);
}
*/
