/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:45:01 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/16 13:45:38 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int             manage_backslash(t_data *data, char **res, int *i)
{
        char    *tmp;
        char    *tmp2;

        tmp = *res;
        ++(*i);
        if (!(tmp2 = ft_strsub(data->token->val, *i, 1))
                        || !(*res = ft_strjoin(*res, tmp2)))
                return (0);
        free(tmp);
        free(tmp2);
        return (1);
}

int		parse_dollar(t_data *data, int *i, char **tmp, char **tmp2)
{
	int j;

	if (data->token->val[++(*i)] == '(')
	{
		(*i)++;
		if (data->token->val[(*i)] == '(')
			if (check_if_arithmetics(&data->token->val[(*i) - 1]) == 1)
				return (0);
	}
	j = 0;
	while (!(data->token->val[*i] == ')' || data->token->val[*i] == ' '
		|| data->token->val[*i] == '\n' || data->token->val[*i] == '\t'
		|| data->token->val[*i] == '\0'))
		++(*i) && ++j;
	if (!(*tmp = ft_strsub(data->token->val, *i - j, j))
			|| (!(*tmp2 = ft_strjoin(*tmp, "="))))
		return (0);
	return (1);
}

int		manage_dollar_other(char *value, t_data *data)
{
	t_data d2;

	d2.env = data->env;
	if (!(d2.args = ft_split_chars(value, &ft_isspace_wnt)))
		return (0);
	ex_exec(d2.env, d2.args);
	return (1);
}

int		manage_dollar(t_data *data, char **res, int *i)
{
	char	*tmp;
	char	*tmp2;
	int		j;
	char	c;

	c = data->token->val[*i + 1];
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
