/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:29:25 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 17:02:02 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_quotes(char *e)
{
	int		valid;
	char	car;
	char	*begin;

	begin = e;
	valid = 0;
	car = 0;
	while (*e)
	{
		if ((e == begin || *(e - 1) != '\\') && (*e == '"' || *e == '\''))
		{
			if (!valid)
			{
				car = *e;
				valid = (car == '"' ? 1 : 2);
			}
			else if (*e == car)
			{
				valid = 0;
				car = 0;
			}
		}
		e++;
	}
	return (valid);
}

void			put_quote_request(int i)
{
	if (i == 1)
		ft_putstr("dquote> ");
	else if (i == 2)
		ft_putstr("quote> ");
}
