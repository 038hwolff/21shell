/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:29:09 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/01 18:41:56 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int     is_arithmetics(char *data, int p)
{
    ft_putendl("coucou");
    if (data[p + 1] == ')')
    {
        return (0);
    }
    //division by zero
    return (0);
}

int 		check_if_arithmetics(char *data)
{
	int po;
	int pf;
	int i;
    char *res;

	po = 0;
	pf = 0;
	i = 0;
	while (data[i++] == '(')
		po++;
	i = ft_strlen(data) - 2;
	while (data[i--] == ')')
		pf++;
	if (po == pf)
	{
        ft_putnbr(po);
        res = ft_strsub(data, po, ft_strlen(&data[po]) - po - 1);
		is_arithmetics(res, po);
		return (1);
	}
	else
		ft_putendl("Parse error");
	return (0);
}
