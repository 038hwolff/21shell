/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_lexer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:38 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/18 15:51:21 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/*
** lexer.c
*/

void			lexical_analysis(t_token **token, char *line);
char			**sh_split_chars(char const *s, int (*is_separator)(char *));

/*
** token.c
*/

t_token			*token_new(char *val, size_t length,
										int type, t_token *next);

/*
** checker.c
*/

t_token			*get_delimitor_token(char **line);

/*
** helper.c
*/

int				is_space_or_tab(char c);
void			discard_spaces_tabs(char **line);
char			*strdquote(char *s);
char			*strquote(char *s);

#endif
