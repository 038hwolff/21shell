/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:25:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/08 21:35:02 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		get_cursor_line(t_edl *edl, int i, char *s)
{
	int ncol;
	int nline;

	nline = 0;
	ncol = edl->prompt_len;
	while (i-- && *s)
	{
		if (*s == '\n' || ncol / edl->col)
		{
			++nline;
			ncol = 0;
		}
		++s;
	}
	return (nline);
}
