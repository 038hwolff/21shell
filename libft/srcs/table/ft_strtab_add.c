/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:11:16 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/17 11:11:19 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strtab_len(char **tab)
{
	int	len;

	len = 0;
	if (tab)
	{
		while (*tab)
		{
			len++;
			tab++;
		}
	}
	return (len);
}

void	ft_strtab_del(char ***tab)
{
	int		i;
	char	**ptr;

	if (tab && *tab)
	{
		ptr = *tab;
		i = 0;
		while (ptr[i])
		{
			ft_strdel(&ptr[i]);
			i++;
		}
		free(ptr);
		*tab = 0;
	}
}

void	ft_strtab_cpy(char **src, char **dest)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = 0;
}

char	**ft_strtab_realloc(char ***src, int len)
{
	char **new;

	if (!(new = ft_strtab_new(len + 1)))
		return (0);
	ft_strtab_cpy(*src, new);
	free(*src);
	*src = 0;
	*src = new;
	return (new);
}

int		ft_strtab_add(char ***tab, char *new)
{
	int		len;
	char	**newtab;

	if (!*tab)
		return (0);
	len = ft_strtab_len(*tab);
	if (!new)
		return (0);
	if (!(newtab = ft_strtab_realloc(tab, len + 1)))
	{
		ft_strtab_del(&newtab);
		return (0);
	}
	*tab = newtab;
	newtab[len] = new;
	return (1);
}
