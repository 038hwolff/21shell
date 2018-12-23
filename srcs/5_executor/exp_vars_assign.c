/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_vars_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:53:50 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/23 17:04:51 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*exp_assign(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)val;
	if (!var_set(&exp->data->env, key, word))
		ft_putendl_fd("Failed to add vars to local", 2);
	return (ft_strdup(word));
}

char	*exp_unhandle(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)exp;
	(void)key;
	(void)val;
	(void)word;
	ft_putendl_fd("shell expansion:: unhandle operator", 2);
	return (0);
}
