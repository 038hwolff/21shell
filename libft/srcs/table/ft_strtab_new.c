/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:11:31 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/17 11:11:34 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtab_new(int len)
{
	char	**new;

	if (!(new = (char**)ft_memalloc(sizeof(*new) * (len + 1))))
		return (0);
	return (new);
}
