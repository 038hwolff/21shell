/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:20:16 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/19 14:15:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

t_token	*get_next_relevant_token(t_token *tok);

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

int					parse(void);

#endif
