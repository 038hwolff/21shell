/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:20:16 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/21 15:29:22 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

char		*check_syntax(t_token *tok);

t_token	*get_next_relevant_token(t_token *tok);
int		is_control_op(int i);
int		is_redir_op(int i);
int		is_agreg_op(int i);


int		parse(t_data *data, t_token *tokens);


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


#endif
