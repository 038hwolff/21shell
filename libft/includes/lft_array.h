/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:57:06 by hben-yah          #+#    #+#             */
/*   Updated: 2018/09/19 19:27:43 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_ARRAY_H
# define LFT_ARRAY_H

void	ft_sortinttab(int *tab, size_t size);
void	ft_sortstrtab(char **tab, size_t size);
char	**ft_strtabdup(char **tab);
size_t	ft_strtablen(char **tab);
char	**ft_strtabncpy(char **dst, char **src, size_t size);
char	**ft_strtabnew(size_t size);
char	**ft_strtabrealloc(char ***tab, size_t size);
void	ft_tabdel(void ***ap);

#endif
