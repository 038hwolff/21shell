/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:54:01 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/10 17:33:26 by hben-yah         ###   ########.fr       */
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
	*complete_from_builtins(t_token *token)
{
	char	*ret;
	int		i;

	ret = NULL;
	i = 0;
	if (ft_strnequ(token->val, "cd", token->length) && ++i)
		ret = (("cd ") + token->length);
	if (ft_strnequ(token->val, "echo", token->length) && ++i)
		ret = (("echo ") + token->length);
	if (ft_strnequ(token->val, "env", token->length) && ++i)
		ret = (("env ") + token->length);
	if (ft_strnequ(token->val, "exit", token->length) && ++i)
		ret = (("exit ") + token->length);
	if (ft_strnequ(token->val, "export", token->length) && ++i)
		ret = (("export ") + token->length);
	if (ft_strnequ(token->val, "set", token->length) && ++i)
		ret = (("set ") + token->length);
	if (ft_strnequ(token->val, "setenv", token->length) && ++i)
		ret = (("setenv ") + token->length);
	if (ft_strnequ(token->val, "unset", token->length) && ++i)
		ret = (("unset ") + token->length);
	if (ft_strnequ(token->val, "unsetenv", token->length) && ++i)
		ret = (("unsetenv ") + token->length);
	return (i > 1 ? "+++" : ret);
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
