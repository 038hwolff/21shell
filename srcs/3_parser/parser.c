/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:32:14 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/11 21:08:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_token
	*sub_check_syntax_errors(t_token *token)
{
	t_token	*next;

	if (is_control_op(token->type)
		&& (next = get_next_relevant_token(token))
		&& is_control_op(next->type))
		return (next);
	if (token->type == CLOSED_PAR
		&& (next = get_next_relevant_token(token))
		&& is_word(next->type))
		return (next);
	if (token->type == OPEN_PAR
		&& (next = get_next_relevant_token(token))
		&& (next->type == CLOSED_PAR || is_control_op(next->type)))
		return (next);
	return (0);
}

char
	*check_syntax_errors(t_token *token)
{
	t_token	*next;

	if (token && is_control_op(token->type))
		return (token->val);
	while (token)
	{
		if (is_unsupported_op(token->type))
			return (token->val);
		if ((is_redir_op(token->type) && token->next
			&& token->next->type != WORD)
			|| (is_agreg_op(token->type) && (!token->next
			|| (token->next->type != IO_NUMBER && token->next->type != WORD))))
			return (token->next->val);
		if ((next = sub_check_syntax_errors(token)))
			return (next->val);
		if (is_word(token->type)
			&& (next = get_next_relevant_token(token))
			&& next->type == OPEN_PAR)
			return (next->next->val);
		token = token->next;
	}
	return (NULL);
}

/*
** CHECK_COMMAND_COMPLETION
** Boucle -> Tant que la commande est incomplète (", ', \, &, |):
**           Lire un input
**           Verifier SIGINT et CTRLD
**           Completer les tokens avec la ligne obtenue
**           Supprimer les token vides
**           Verifier les erreurs de syntaxes
*/

int
	check_command_completion(t_data *data)
{
	int ret;

	if (!data->token)
		return (0);
	while (data->token
		&& (data->incomp_type = is_command_incomplete(data->token)) != COMPLETE)
	{
		if (data->oneshot)
			return (put_eof_exception(data));
		set_special_prompt(data);
		read_line();
		if ((ret = check_cancel(data, &data->edl.line)))
			return (ret == 1 ? -1 : 0);
		complete_tokens(data->token, data->incomp_type, &data->edl.line);
		del_tokens_if(&data->token, &token_is_empty);
		if (data->token
			&& syntax_exception(check_syntax_errors(data->token), data->subcmd))
			return (0);
	}
	data->incomp_type = COMPLETE;
	set_special_prompt(data);
	return (1);
}

/*
** CHECK_HEREDOCS
*/

int
	check_heredocs(t_data *data)
{
	int		car;
	t_token *token;

	token = data->token;
	while (token)
	{
		if (token->type == DOUBLELESS && token->next)
		{
			if ((car = has_quotes_or_backslash(token->next->val)))
				remove_quotes_and_backslash(&token->next->val);
			if (!get_heredoc_lines(data, token, car))
				return (0);
			if (!car)
				exp_vars(&token->heredoc, data, 1);
		}
		token = token->next;
	}
	return (1);
}

/*
** PARSER
** 1 - Check les erreurs de syntax.
** syntax error exception.
** 2 - Verifie qu'une commande est complete (inhibiteurs, backslash)
** Sinon la complète par des inputs
** Peut retirer des caractères ce qui peut entrainer des maillons vides
** qu'il faut supprimer.
** 3 - Verifie si heredoc
** Si oui, pour chaque heredoc recupere les inputs
*/

int
	parser(t_data *data)
{
	int ret;

	data->dev && print_lex(data->token, "LEXER");
	ret = 0;
	if (data->token)
	{
		if (syntax_exception(check_syntax_errors(data->token), data->subcmd)
			|| (ret = check_command_completion(data)) < 1)
			return (ret);
		del_tokens_if(&data->token, &token_is_newline);
		if (!check_heredocs(data))
			return (-1);
	}
	return (1);
}
