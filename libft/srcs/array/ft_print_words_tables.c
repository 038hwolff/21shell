/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:13:50 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 17:11:19 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_words_tables(char **tab)
{
	int i;
	int	index;

	if (tab)
	{
		index = 0;
		while (tab[index])
		{
			i = 0;
			while (tab[index][i])
			{
				ft_putchar(tab[index][i]);
				i++;
			}
			index++;
			ft_putchar('\n');
		}
	}
}
