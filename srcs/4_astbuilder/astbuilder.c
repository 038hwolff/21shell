/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astbuilder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:02:24 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/28 17:58:54 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	add_node(t_ast **tree, int type)
{
	t_ast *tmpNode;
	t_ast *tmpTree;
	t_ast *elem;

	tmpTree = *tree;
	elem = malloc(sizeof(t_ast));
	elem->type = type;
	elem->left = NULL;
	elem->right = NULL;
	if (tmpTree)
	{
		while (tmpTree)
		{
			tmpNode = tmpTree;
			if (type > tmpTree->type)
			{
				tmpTree = tmpTree->right;
				if (!tmpTree)
					tmpNode->right = elem;
			}
			else
			{
				tmpTree = tmpTree->left;
				if (!tmpTree)
					tmpNode->left = elem;
			}
		}
	}
	else
		*tree = elem;
}

void	build_ast(t_token *token)
{
	t_ast	*tree;

	tree = NULL;
	add_node(&tree, token->type);
}