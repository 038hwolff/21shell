/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_astbuilder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:31 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/16 17:56:25 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_ASTBUILDER_H
# define E_ASTBUILDER_H

/*
** astbuilder.c
*/

void			build_ast(t_data *data);
int				print_ast(t_ast *ast);
int				get_rank(int type);
void			tokendel(t_token **tok);
t_token			*tokendup(t_token *tok);
t_token			*get_primary_prev_token(t_token **primary_prev, t_token *token);
void			pop_par(t_token *chosen, t_token **chosen_prev);

#endif
