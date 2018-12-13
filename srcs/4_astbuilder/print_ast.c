/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:38:09 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/13 14:41:25 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void
	print_node(t_ast *ast, char *name, int depth)
{
	if (!ast || !name)
		return ;
	if (ast->right)
		print_node(ast->right, "right", depth + 1);
	ft_printf("%*s", depth * 14, "");
	ft_printf(".. %5s %d ..%s\n", name, depth, "");

	ft_printf("%*s", (depth * 14) + 1, "");
	if (ast->left_arg)
		ft_printf("%s ", ast->left_arg->val);
	ft_printf("%s", ast->token->val);
	if (ast->right_arg)
		ft_printf(" %s", ast->right_arg->val);
	ft_printf("\n");
	ft_printf("%*s", depth * 14, "");
	ft_printf(".............%s\n", "");
	if (ast->left)
		print_node(ast->left, "left", depth + 1);
}

void
	print_ast(t_ast *ast)
{
	if (ast)
	{
		ft_printf("\n--- AST ---\n\n");
		print_node(ast, "begin", 0);
		ft_printf("\n-----------\n");
	}
}
