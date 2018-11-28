/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_astbuilder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:31 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/28 18:08:14 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTBUILDER_H
# define ASTBUILDER_H



/*
** astbuilder.c
*/

void	            build_ast(t_token *token);
void	        add_node(t_ast **tree, int type);


#endif
