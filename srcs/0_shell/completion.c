/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:54:01 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/11 15:09:34 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char
	*complete_from_path_var_n(char **path, char *input)
{
	DIR				*dir;
	struct dirent	*ent;
	char			*ret;
	int				i;

	i = 0;
	ret = NULL;
	remove_backslash_before_spechar(input);
	while (path[i] && (dir = opendir(remove_backslash_before_spechar(path[i]))))
	{
		while ((ent = readdir(dir)))
			if (!check_file(&ret, ent->d_name, input, path[i]))
			{
				closedir(dir);
				return (NULL);
			}
		closedir(dir);
		++i;
	}
	return (ret);
}

static char
	*complete_from_path_var(char **env, char *input)
{
	char			**path;
	char			*ret;

	ret = var_get_val(env, "PATH");
	path = NULL;
	if (ret)
		try_m(path = ft_strsplit(ret, ':'));
	ret = NULL;
	if (path && *path)
		ret = complete_from_path_var_n(path, input);
	ft_tabdel((void***)&path);
	return (ret);
}

static char
	*complete_bin(char **env, t_token *token)
{
	char *ret;
	char *ret2;

	if (token->val[0] != '/' && !(ft_strnequ(token->val, "./", 2)))
	{
		ret = complete_from_builtins(token);
		if (ret && ft_strequ(ret, "+++"))
			return (NULL);
		ret2 = complete_from_path_var(env, token->val);
		if (ret && !ret2)
			return (ret);
		if (!ret && ret2)
			return (ret2);
		if (ret && ret2 && ft_strequ(ret, ret2))
			return (ret);
		return (NULL);
	}
	else
		return (complete_from_given_path(token->val));
}

static char
	*complete_var(t_data *data, t_token *token)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*ret;

	k = 1;
	if (token->val[1] == '{')
		++k;
	i = 0;
	len = ft_strlen(token->val + k);
	while (data->env[i] && !ft_strnequ(data->env[i], token->val + k, len))
		++i;
	j = 0;
	while (data->loc[j] && !ft_strnequ(data->loc[j], token->val + k, len))
		++j;
	ret = NULL;
	if (data->env[i] && !data->loc[j])
		ret = try_m(ft_strsub(data->env[i], len,
			ft_strchr(data->env[i], '=') - data->env[i] + 1));
	if (!data->env[i] && data->loc[j])
		ret = try_m(ft_strsub(data->loc[j], len,
			ft_strchr(data->loc[j], '=') - data->loc[j] + 1));
	return (ret);
}

char
	*completion(t_data *data, char *line)
{
	t_token *lex;
	t_token *cpy;
	t_token *prev;
	char	*ret;

	if (!line || !*line)
		return (NULL);
	ret = NULL;
	lex = NULL;
	prev = NULL;
	lexical_analysis(&lex, line);
	if ((cpy = lex))
	{
		while (lex->next && (prev = lex))
			lex = lex->next;
		if (ft_strchr(lex->val, '$') || ft_strstr(lex->val, "${"))
			ret = complete_var(data, lex);
		else if (!prev)
			ret = (lex->type == WORD ? complete_bin(data->env, lex) : NULL);
		else if (lex->type == WORD)
			ret = (prev->type != WORD ? complete_bin(data->env, lex)
								: complete_from_given_path(lex->val));
		free_token(&cpy);
	}
	return (ret);
}
