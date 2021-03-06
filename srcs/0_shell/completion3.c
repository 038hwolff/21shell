/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:07:11 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/23 15:09:26 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char
	*complete_from_builtins(t_token *token)
{
	char	*ret;
	int		i;

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
	ret = (i == 1 && ret ? try_m(ft_strdup(ret)) : NULL);
	return (i < 2 ? ret : "+++");
}
