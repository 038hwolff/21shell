/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:20:16 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 18:27:37 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_PARSER_H
# define D_PARSER_H

char	*check_syntax_errors(t_token *token);

t_token	*get_next_relevant_token(t_token *tok);
int		is_control_op(int i);
int		is_redir_op(int i);
int		is_agreg_op(int i);
int		is_unsupported_op(int op);

int		parser(t_data *data);

/*
** quotes.c
*/

int		is_quotes(char *e);
void	put_quote_request(int i);

/*
** backslash.c
*/

int		manage_backslash(t_data *data, char **res, int *i);

/*
** parser.c
*/

int		check_command(t_data *data, t_token **token);
t_token	*get_last_token(t_token *token);

void	complete_command_backslash(t_token *token, char **line);
void	complete_command_quote(t_token *token, char **line, char quotetype);
int		is_command_incomplete(t_token *token);

int		token_is_empty(t_token *token);
int		token_is_newline(t_token *token);
void	tokendelone(t_token **elem);
void	del_tokens_if(t_token **alst, int (*token_is)(t_token *));

int		check_heredoc(t_data *data, t_token *token);
int		pop_char(char **line, int i);

int		get_heredoc_lines(t_data *data, t_token *token, int quoted);
int		pop_backslashed_nl(char **line);

void	set_special_prompt(t_data *data);

int		check_backslash(t_token *token);
char	check_quote(t_token *token);
int		check_pipe(t_token *token);
int		check_or(t_token *token);
int		check_and(t_token *token);
void	pop_backslash_in_heredoc(char **s);

int		check_cancel(t_data *data, char **line);

void	complete_tokens(t_token *token, int incomp_type, char *line);

int		has_quotes_or_backslash(char *s);
void	remove_quotes_and_backslash(char **line);

void	merge_tokens(t_token *t1, t_token *t2);
void	append_token_value(t_token *token, int i, char **line);

int		expand_dquote(char **line, int cur);
int		expand_quote(char **line, int cur);

#endif
