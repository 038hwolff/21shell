/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_convert.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:58:50 by hben-yah          #+#    #+#             */
/*   Updated: 2018/09/19 19:00:41 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_CONVERT_H
# define LFT_CONVERT_H

int		ft_atoi(const char *str);
int		ft_atoi_base(char *str, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_itoa(int n);
char	*ft_itoa_base(int n, char *base);

#endif
