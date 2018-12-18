/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:57:35 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 15:02:04 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*tristrjoin(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*ret;

	if (!(ret = ft_strjoin(s1, s2)))
		return (NULL);
	tmp = ret;
	if (!(ret = ft_strjoin(ret, s3)))
		return (NULL);
	ft_strdel(&tmp);
	return (ret);
}
