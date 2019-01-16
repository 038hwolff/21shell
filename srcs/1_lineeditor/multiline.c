/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:25:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/16 12:05:04 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		get_cursor_line(t_edl *edl, int i, char *s)
{
	int ncol;
	int nline;
	int	j;

	nline = 0;
	ncol = edl->prompt_len;
	j = 0;
	while (j < i && s[j])
	{
		if (s[j] == '\n' || ncol % edl->col == 0)
		{
			++nline;
			ncol = 0;
		}
		++j;
		++ncol;
	}
	return (nline);
}
