/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_other.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:58:50 by hben-yah          #+#    #+#             */
/*   Updated: 2018/10/30 17:43:58 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_OTHER_H
# define LFT_OTHER_H

# define BUFF_SIZE 100
# define FD_MAX 16384

int		ft_indexof(char c, char *str);
int		ft_lininterp(int p1, int p2, double ratio);
double	ft_rlininterp(double px, double p1, double p2);
int		get_next_line(const int fd, char **line);
char	**ft_split(const char *cmd);

#endif
