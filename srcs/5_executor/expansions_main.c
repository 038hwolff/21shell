/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:49:16 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/17 15:32:40 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

// int		manage_rest(t_data *data, char **res, int *i)
// {
// 	char	*tmp2;
// 	char	*tmp;

// 	tmp = *res;
// 	if (!(tmp2 = ft_strsub(data->token->val, *i, 1)) ||
// 		!(*res = ft_strjoin(*res, tmp2)))
// 		return (0);
// 	free(tmp);
// 	free(tmp2);
// 	return (1);
// }

// int		expansions(t_data *data)
// {
// 	char	*res;
// 	char	*tmp;
// 	int		i;

// 	i = 0;
// 	if (!(res = ft_strdup("")))
// 		return (0);
// 	while (data->token->val[i])
// 	{
// 		if (data->token->val[i] == '~')
// 			go_home(data, &res);
// 		else if (data->token->val[i] == '$')
// 			manage_dollar(data, &res, &i);
// 		else if (data->token->val[i] == '\\')
// 			manage_backslash(data, &res, &i);
// 		else
// 			manage_rest(data, &res, &i);
// 		i++;
// 	}
// 	tmp = data->token->val;
// 	data->token->val = res;
// 	free(tmp);
// 	return (1);
// } 
