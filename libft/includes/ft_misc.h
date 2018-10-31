/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:58:50 by hben-yah          #+#    #+#             */
/*   Updated: 2018/10/31 11:51:13 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MISC_H
# define FT_MISC_H

# define BUFF_SIZE 100
# define FD_MAX 16384

int		ft_indexof(char c, char *str);
int		ft_lininterp(int p1, int p2, double ratio);
double	ft_rlininterp(double px, double p1, double p2);

#endif
