/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:54:01 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/21 19:10:05 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char
	*complete_from_given_path(char *input)
{
	DIR				*dir;
	struct dirent	*ent;
	char			*n;
	char			*path;
	char			*ret;

	n = ft_strrchr(input, '/');
	try_m((path = (n ? ft_strsub(input, 0, ft_strrchr(input, '/') - input + 1)
					: ft_strdup("."))));
	ret = NULL;
	if (path && (dir = opendir(path)))
	{
		!(n && ++n) && (n = input);
		while ((ent = readdir(dir)))
			if (ft_strnequ(ent->d_name, n, ft_strlen(n)))
				if (ret
					|| !try_m((ret = ft_strdup(ent->d_name + ft_strlen(n)))))
				{
					ft_strdel(&ret);
					break ;
				}
		closedir(dir);
	}
	ft_strdel(&path);
	return (ret);
}

static char
	*complete_from_path_n(char **path, char *input)
{
	DIR				*dir;
	struct dirent	*ent;
	char			*ret;
	int				i;

	i = 0;
	ret = NULL;
	while (path[i] && (dir = opendir(path[i])))
	{
		while ((ent = readdir(dir)))
			if (ft_strnequ(ent->d_name, input, ft_strlen(input)))
			{
				if (ret)
				{
					closedir(dir);
					ft_strdel(&ret);
					return (NULL);
				}
				try_m(ret = ft_strdup(ent->d_name + ft_strlen(input)));
			}
		closedir(dir);
		++i;
	}
	return (ret);
}

static char
	*complete_from_paths(char **env, char *input)
{
	char			**path;
	char			*ret;
	int				i;

	i = 0;
	while (env[i] && !ft_strnequ(env[i], "PATH=", 5))
		++i;
	path = NULL;
	ret = NULL;
	if (env[i])
		try_m(path = ft_strsplit(env[i], ':'));
	if (path && *path)
	{
		*path = ft_strncpy(*path, (*path + 5), ft_strlen(*path));
		ret = complete_from_path_n(path, input);
	}
	ft_tabdel((void***)&path);
	return (ret);
}

static char
	*complete_bin(char **env, t_token *token)
{
	if (token->val[0] != '/' && !(ft_strnequ(token->val, "./", 2)))
		return (complete_from_paths(env, token->val));
	else
		return (complete_from_given_path(token->val));
}

char
	*completion(t_data *data)
{
	t_token *lex;
	char	*ret;

	if (!data->edl.line || !*data->edl.line)
		return (NULL);
	ret = NULL;
	lex = NULL;
	lexical_analysis(&lex, data->edl.line);
	if (lex)
	{
		while (lex->next && lex->next->next)
			lex = lex->next;
		if (!lex->next)
			ret = (lex->type == WORD ? complete_bin(data->env, lex) : NULL);
		else if (lex->next->type == WORD)
			ret = (lex->type != WORD ? complete_bin(data->env, lex->next)
								: complete_from_given_path(lex->next->val));
		free_token(&lex);
	}
	return (ret);
}
