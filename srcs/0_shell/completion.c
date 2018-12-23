/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:54:01 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/23 13:56:28 by hben-yah         ###   ########.fr       */
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
		ft_printf("\n%s\n", path[i]);
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
		ret = complete_from_path_var_n(path, input);
	}
	ft_tabdel((void***)&path);
	return (ret);
}

static char
	*complete_bin(char **env, t_token *token)
{
	if (token->val[0] != '/' && !(ft_strnequ(token->val, "./", 2)))
		return (complete_from_path_var(env, token->val));
	else
		return (complete_from_given_path(token->val));
}

char
	*completion(t_data *data, char *line)
{
	t_token *lex;
	char	*ret;

	if (!line || !*line)
		return (NULL);
	ret = NULL;
	lex = NULL;
	lexical_analysis(&lex, line);
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
