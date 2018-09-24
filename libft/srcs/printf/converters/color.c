/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:53:07 by hben-yah          #+#    #+#             */
/*   Updated: 2018/08/09 20:13:45 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	convert_color(t_formatter *fmt, t_strbuffer *sb, int light)
{
	char	*s;
	int		color;

	color = fmt->width;
	color %= 7;
	if (color > 0)
		color += 30;
	trial((s = ft_itoa(color)) != NULL);
	add(sb, (light ? "\e[1;" : "\e[0;"), 4);
	add(sb, s, ft_strlen(s));
	add(sb, "m", 1);
	fmt->width = 0;
	free(s);
	return (0);
}

int	convert_q(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	(void)ap;
	return (convert_color(fmt, sb, 0));
}

int	convert_q_up(t_formatter *fmt, t_strbuffer *sb, va_list ap)
{
	(void)ap;
	return (convert_color(fmt, sb, 1));
}
