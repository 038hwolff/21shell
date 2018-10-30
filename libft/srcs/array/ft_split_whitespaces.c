/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:10:39 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 17:11:23 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nb_words(const char *input)
{
	int		last_is_space;
	int		cpt;

	last_is_space = 1;
	cpt = 0;
	while (*input)
	{
		if (*input == ' ' || *input == '\t' || *input == '\n')
			last_is_space = 1;
		else
		{
			if (last_is_space)
				cpt++;
			last_is_space = 0;
		}
		input++;
	}
	return (cpt);
}

int		is_char_separator(char c)
{
	return (c == '\0' ||
			c == ' ' ||
			c == '\t' ||
			c == '\r' ||
			c == '\n');
}

char	*str_clone(const char *input)
{
	int		i;
	int		n;
	char	*str;

	n = 0;
	while (input[n] && !is_char_separator(input[n]))
		n++;
	if (!(str = malloc((1 + n) * sizeof(*str))))
		return (NULL);
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	remplir_table(char **out, const char *input)
{
	int		last;
	int		n;

	last = 1;
	n = 0;
	while (*input)
	{
		if (is_char_separator(*input))
			last = 1;
		else if (last)
		{
			out[n++] = str_clone(input);
			last = 0;
		}
		input++;
	}
	out[n] = NULL;
}

char	**ft_split_whitespaces(char *str)
{
	char	**out;
	size_t	len;

	out = NULL;
	len = nb_words(str);
	if (!(out = malloc((len + 1) * sizeof(char*))))
		return (NULL);
	if (out == NULL)
		exit(EXIT_FAILURE);
	remplir_table(out, str);
	return (out);
}
