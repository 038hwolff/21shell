/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 01:06:44 by pespalie          #+#    #+#             */
/*   Updated: 2018/10/30 17:45:54 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*ft_fill(const char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_count(const char *command)
{
	int	count;

	count = 0;
	while (*command)
	{
		while (*command && (*command == ' ' || *command == '\n'
		|| *command == '\t'))
			command++;
		if (*command && *command != ' ' && *command != '\n'
		&& *command != '\t')
		{
			count++;
			while (*command && *command != ' ' && *command != '\n'
			&& *command != '\t')
				command++;
		}
	}
	return (count);
}

char		**ft_split(const char *cmd)
{
	char	**tab;
	int		word;
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	word = ft_count(cmd);
	if (!(tab = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	while (*cmd)
	{
		while (*cmd && (*cmd == ' ' || *cmd == '\n' || *cmd == '\t'))
			cmd++;
		if (*cmd && (*cmd != ' ' && *cmd != '\n' && *cmd != '\t'))
		{
			tab[i] = ft_fill(cmd);
			i++;
			while (*cmd && *cmd != ' ' && *cmd != '\n' && *cmd != '\t')
				cmd++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
