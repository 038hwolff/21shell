/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:43:01 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/06 19:44:47 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
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
