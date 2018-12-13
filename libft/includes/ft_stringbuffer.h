/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringbuffer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:58:50 by hben-yah          #+#    #+#             */
/*   Updated: 2018/10/31 11:47:02 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGBUFFER_H
# define FT_STRINGBUFFER_H

# define STRINGBUFFER_SIZE 1024

typedef struct	s_strbuffer
{
	char	*str;
	size_t	length;
	size_t	max_len;
}				t_strbuffer;

int				sb_add(t_strbuffer *sb, const char *data, size_t len);
int				sb_check_free_space(t_strbuffer *sb, size_t len);
int				sb_remalloc(t_strbuffer *sb, size_t new_len);
int				sb_slide(t_strbuffer *sb, size_t bef, size_t aft);
int				sb_init(t_strbuffer *sb);

#endif
