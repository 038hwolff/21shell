/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_vars_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:01:16 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/30 13:52:12 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_varsexp_rules	g_varsexp_rules[12] = {
	{":-", exp_sub_param, exp_sub_word, exp_sub_word},
	{"-", exp_sub_param, exp_sub_null, exp_sub_word},
	{":=", exp_sub_param, exp_assign, exp_assign},
	{"=", exp_sub_param, exp_sub_null, exp_assign},
	{":?", exp_sub_param, exp_sub_error, exp_sub_error},
	{"?", exp_sub_param, exp_sub_null, exp_sub_error},
	{":+", exp_sub_word, exp_sub_null, exp_sub_null},
	{"+", exp_sub_word, exp_sub_word, exp_sub_null},
	{"%%", exp_unhandle, exp_unhandle, exp_unhandle},
	{"%", exp_unhandle, exp_unhandle, exp_unhandle},
	{"##", exp_unhandle, exp_unhandle, exp_unhandle},
	{"#", exp_unhandle, exp_unhandle, exp_unhandle}
};

static t_varsexp_rules	*get_rules(char *s)
{
	int i;

	i = 0;
	while (i < 12)
	{
		if (ft_strstr(s, g_varsexp_rules[i].op))
			return (&g_varsexp_rules[i]);
		i++;
	}
	return (0);
}

static void				apply_rule(t_varsexp *vexp)
{
	char	*word;
	char	*val;
	char	*pos;

	pos = ft_strstr(vexp->str, vexp->rule->op);
	*pos = 0;
	word = &pos[ft_strlen(vexp->rule->op)];
	(val = var_get_val(vexp->data->spe, vexp->str))
	|| (val = var_get_val(vexp->data->loc, vexp->str))
	|| (val = var_get_val(vexp->data->env, vexp->str));
	if (!val)
		vexp->res = vexp->rule->unset(vexp, vexp->str, val, word);
	else if (val && !*val)
		vexp->res = vexp->rule->null(vexp, vexp->str, val, word);
	else
		vexp->res = vexp->rule->set(vexp, vexp->str, val, word);
}

static	char			*exp_res_rules(t_varsexp *vexp)
{
	char	*tmp;

	ft_strrmvchr(ft_strlastchr(vexp->str));
	ft_strrmvchr(vexp->str);
	if (*vexp->str == '#')
	{
		ft_strrmvchr(vexp->str);
		vexp->format = NBR_FORMAT;
	}
	if ((vexp->rule = get_rules(vexp->str)))
		apply_rule(vexp);
	else
	{
		(tmp = var_get_val(vexp->data->spe, vexp->str))
		|| (tmp = var_get_val(vexp->data->loc, vexp->str))
		|| (tmp = var_get_val(vexp->data->env, vexp->str));
		try_m((vexp->res = ft_strdup((tmp ? tmp : ""))));
	}
	if (vexp->res && vexp->format == NBR_FORMAT)
	{
		tmp = ft_itoa(ft_strlen(vexp->res));
		free(vexp->res);
		vexp->res = tmp;
	}
	return (vexp->res);
}

static char				*exp_res_norules(t_varsexp *vexp)
{
	char	*tmp;

	(tmp = var_get_val(vexp->data->spe, vexp->str))
	|| (tmp = var_get_val(vexp->data->loc, vexp->str))
	|| (tmp = var_get_val(vexp->data->env, vexp->str));
	vexp->res = (tmp) ? ft_strdup(tmp) : ft_strdup("");
	return (vexp->res);
}

char					*exp_vars_get(char *str, t_data *data)
{
	t_varsexp	vexp;

	vexp.format = STR_FORMAT;
	if (!str)
		return (ft_strdup(""));
	vexp.data = data;
	vexp.str = str;
	vexp.res = 0;
	if (*str == '{' && *(ft_strlastchr(str)) == '}')
		return (exp_res_rules(&vexp));
	return (exp_res_norules(&vexp));
}
