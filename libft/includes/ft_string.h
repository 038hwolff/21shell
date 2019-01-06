/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:58:50 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/06 17:47:18 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "ft_stringbuffer.h"

/*
**	Flag used by ft_strjoin3f
*/

# define FREE_LEFT 0x01
# define FREE_MID 0x02
# define FREE_RIGHT 0x04

void	ft_charswap(char *a, char *b);
int		ft_hasnodupl(char *str);
char	*ft_printabilize(char *str, char c);
char	**ft_split_chars(char const *s, int (*is_separator)(int));
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
int		ft_strequ(char const *s1, char const *s2);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin3(char const *s1, char const *s2, char const *s3);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strrev(char *str);
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtolower(char *str);
char	*ft_strtoupper(char *str);
char	*ft_strtrim(char const *s);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_wrdcnt(const char *s, char c);
void	ft_strrmvchr(char *s);
char	*ft_strlastchr(char *s);
char	*ft_strjoin3f(char *s1, char *s2, char *s3, char flag);

#endif
