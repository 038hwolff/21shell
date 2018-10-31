/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:45:01 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 16:57:02 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		parse_dollar(t_data *data, int *i, char **tmp, char **tmp2)
{
	int j;

	if (data->entry[++(*i)] == '(')
		(*i)++;
	j = 0;
	while (!(data->entry[*i] == ')' || data->entry[*i] == ' '
		|| data->entry[*i] == '\n' || data->entry[*i] == '\t'
		|| data->entry[*i] == '\0'))
		++(*i) && ++j;
	if (!(*tmp = ft_strsub(data->entry, *i - j, j))
			|| (!(*tmp2 = ft_strjoin(*tmp, "="))))
		return (0);
	return (1);
}

int		manage_dollar(t_data *data, char **res, int *i)
{
	char	*tmp;
	char	*tmp2;
	int		j;
	char	c;

	c = data->entry[*i + 1];
	if (!parse_dollar(data, i, &tmp, &tmp2))
		return (0);
	j = 0;
	while (data->env[j] &&
			(ft_strncmp(data->env[j], tmp2, ft_strlen(tmp2)) != 0))
		j++;
	if (data->env[j] && c != '(')
	{
		free(tmp);
		tmp = *res;
		if (!(*res = ft_strjoin(*res, data->env[j] + ft_strlen(tmp2))))
			return (0);
		--(*i);
	}
	else if (c == '(')
		trial((int)(manage_dollar_other(tmp, data)));
	free(tmp);
	free(tmp2);
	return (1);
}

int		manage_dollar_other(char *value, t_data *data)
{
	t_data d2;

	d2.env = data->env;
	if (!(d2.args = ft_split_chars(value, &ft_isspace_wnt)))
		return (0);
	ex_exec(&d2);
	return (1);
}