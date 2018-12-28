/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:59:41 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/29 00:09:38 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	expansion(t_data *data, t_token *tkn)
{
	exp_tilde(&tkn->val, data);
	exp_vars(&tkn->val, data, 0);
	exp_substit_cmd(&tkn->val, data);
	exp_quotes(&tkn->val);
}
