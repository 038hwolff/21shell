/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:20:16 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/27 14:52:43 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

char		*check_syntax_errors(t_token *token);

t_token	*get_next_relevant_token(t_token *tok);
int		is_control_op(int i);
int		is_redir_op(int i);
int		is_agreg_op(int i);


int		parser(t_token **token);


/*
** quotes.c
*/

int					is_quotes(char *e);
void				put_quote_request(int i);

/*
** backslash.c
*/

int					manage_backslash(t_data *data, char **res, int *i);

/*
** parser.c
*/

int		check_command(t_data *data, t_token **token);
t_token	*get_last_token(t_token *token);

void	complete_command_backslash(t_token *token, char **line);
void	complete_command_quote(t_token *token, char **line, char quotetype);
int		check_incomplete_command(t_token *token);




#endif
