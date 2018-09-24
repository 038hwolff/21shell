/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_put.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:58:50 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/08 18:50:13 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_PUT_H
# define LFT_PUT_H

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int nb);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putnbrtab(int *tab, size_t size);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstrtab(char **tab);

#endif
