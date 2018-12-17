/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_astbuilder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:31 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 18:27:44 by hwolff           ###   ########.fr       */
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

#endif
