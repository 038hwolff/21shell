/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:13:16 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/06 17:47:03 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free3if(char *s1, char *s2, char *s3, char flag)
{
	if (s1 && (flag & FREE_LEFT))
		free(s1);
	if (s2 && (flag & FREE_MID))
		free(s2);
	if (s3 && (flag & FREE_RIGHT))
		free(s3);
}

char		*ft_strjoin3f(char *s1, char *s2, char *s3, char flag)
{
	char	*new;
	int		len;

	len = (s1) ? ft_strlen(s1) : 0;
	len += (s2) ? ft_strlen(s2) : 0;
	len += (s3) ? ft_strlen(s3) : 0;
	if (!(new = ft_strnew(len)))
	{
		free3if(s1, s2, s3, flag);
		return (0);
	}
	if (s1)
		ft_strcat(new, s1);
	if (s2)
		ft_strcat(new, s2);
	if (s3)
		ft_strcat(new, s3);
	free3if(s1, s2, s3, flag);
	return (new);
}
