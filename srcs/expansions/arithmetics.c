/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:29:09 by hwolff            #+#    #+#             */
/*   Updated: 2018/11/05 16:38:05 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int     is_arithmetics(char *data, int p)
{
    if (data[p + 1] == ')')
        return (0);
    //division by zero
    return (0);
}

static int	is_operator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
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
	i = 0;
	if (po == pf)
	{
        res = ft_strsub(data, po, ft_strlen(&data[po]) - po - 1);
		while ((size_t)i++ < ft_strlen(res))
			if (is_hexa(res[i]) == 0 && is_operator(res[i]) == 0 && res[i] != ' ' && res[i] != '\0')
				return (0);
		is_arithmetics(res, po);
		return (1);
	}
	else
		ft_putendl("Parse error");
	return (0);
}

// int		main(int argc, char **argv, char **envp)
// {
// 	t_data	data;
// 	(void)argc;

// 	data.env = envp;
// 	data.args = argv;
	
// 	check_if_arithmetics(data.args[1]);
// 	return (0);
// }
