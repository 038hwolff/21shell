/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:57:35 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/16 13:59:26 by hwolff           ###   ########.fr       */
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
	free(tmp);
	return (ret);
}
