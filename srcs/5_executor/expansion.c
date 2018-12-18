/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:59:41 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/17 18:59:42 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	expansion(t_data *data, t_token *tkn)
{
	exp_tilde(&tkn->val, data);
	exp_vars(&tkn->val, data, 0);
	exp_quotes(&tkn->val);
}
