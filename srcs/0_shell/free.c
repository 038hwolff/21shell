/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:17:27 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/17 15:21:31 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

// void			cd_free(char **tmp, t_data *ndata)
// {
// 	free_tab(&ndata->env);
// 	free_tab(&ndata->args);
// 	free_tab(&tmp);
// }

void		free_tab(char ***table)
{
	int	f;

	if (table && *table)
	{
		f = 0;
		while ((*table)[f])
		{
			ft_strdel(&((*table)[f]));
			f++;
		}
		free(*table);
		*table = NULL;
	}
}

// void		free_tab_content(char ***table)
// {
// 	int	f;

// 	if (table && *table)
// 	{
// 		f = 0;
// 		while ((*table)[f])
// 		{
// 			ft_strdel(&((*table)[f]));
// 			f++;
// 		}
// 	}
// }


void		free_token(t_token **token)
{
	t_token *tok;
	t_token *tmp;

	if (token && *token)
	{
		tok = *token;
		while (tok)
		{
			tmp = tok;
			if (tmp->val)
				ft_strdel(&tmp->val);
			if (tmp->heredoc)
				ft_strdel(&tmp->heredoc);
			tok = NULL;
			// tok = tok->next;
 			free(tmp);
		}
		*token = NULL;
	}
}

void		free_ast(t_ast **ast)
{
	if (ast && *ast)
	{
		if ((*ast)->right)
			free_ast(&(*ast)->right);
		if ((*ast)->right_arg)
			free_token(&(*ast)->right_arg);
		if ((*ast)->token)
			free_token(&(*ast)->token);
		if ((*ast)->left_arg)
			free_token(&(*ast)->left_arg);
		if ((*ast)->left)
		free_ast(&(*ast)->left);
		free(*ast);
		*ast = NULL;
	}
}
