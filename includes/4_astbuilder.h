/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_astbuilder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:19:31 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/15 16:57:07 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTBUILDER_H
# define ASTBUILDER_H



/*
** astbuilder.c
*/

void			build_ast(t_data *data);
int			print_ast(t_ast *ast);
int				get_rank(int type);

#endif
