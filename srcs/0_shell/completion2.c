/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 00:39:27 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/23 14:03:41 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char
	*remove_backslash_before_spechar(char *s)
{
	int		i;
	int		decal;
	int		len;

	i = 0;
	decal = 0;
	len = ft_strlen(s);
	while (i < len - decal)
	{
		if (s[i + decal] == '\\' && ft_indexof(s[i + decal + 1], "|&;<> ") > -1)
			++decal;
		s[i] = s[i + decal];
		++i;
	}
	while (i < len)
		s[i++] = 0;
	return (s);
}

char
	*insert_backslash_before_spechar(char *s)
{
	int		i;
	int		decal;
	char	*ret;
	char	*tmp;

	try_m((ret = ft_strdup(s)));
	i = 0;
	decal = 0;
	while (s[i])
	{
		if (ft_indexof(s[i], "|&;<> ") > -1)
		{
			try_m((tmp = ft_strnew(ft_strlen(ret) + 1)));
			ft_strncpy(tmp, ret, i + decal);
			tmp[i + decal] = '\\';
			ft_strcpy(tmp + i + decal + 1, ret + i + decal);
			ft_strdel(&ret);
			ret = tmp;
			++decal;
		}
		++i;
	}
	return (ret);
}

int
	is_a_directory(char *dir, char *file)
{
	struct stat		stats;
	char			*path;
	int				ret;

	try_m((path = ft_strjoin(dir, file)));
	ret = 0;
	if (stat(path, &stats) != -1)
		ret = S_ISDIR(stats.st_mode);
	ft_strdel(&path);
	return (ret);
}

int
	check_file(char **ret, char *entry, char *file, char *path)
{
	char			*tmp;
	int				len;

	len = ft_strlen(file);
	if (ft_strnequ(entry, file, len))
	{
		if (*ret)
		{
			ft_strdel(ret);
			return (0);
		}
		try_m((tmp = insert_backslash_before_spechar(entry + len)));
		try_m((*ret = ft_strjoin(tmp,
						(is_a_directory(path, entry) ? "/" : " "))));
		ft_strdel(&tmp);
	}
	return (1);
}

char
	*complete_from_given_path(char *input)
{
	DIR				*dir;
	struct dirent	*ent;
	char			*n;
	char			*path;
	char			*ret;

	remove_backslash_before_spechar(input);
	n = ft_strrchr(input, '/');
	try_m((path = (n ? ft_strsub(input, 0, ft_strrchr(input, '/') - input + 1)
					: ft_strdup("./"))));
	ret = NULL;
	if (path && (dir = opendir(path)))
	{
		!(n && ++n) && (n = input);
		while ((ent = readdir(dir)))
			if (!check_file(&ret, ent->d_name, n, path))
				break ;
		closedir(dir);
	}
	ft_strdel(&path);
	return (ret);
}
