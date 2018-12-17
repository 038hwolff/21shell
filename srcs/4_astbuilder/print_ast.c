/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:38:09 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 10:06:56 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int
	print_node(t_ast *ast, char *name, int depth)
{
	int ret;

	ret = 0;
	if (!ast || !name)
		return (ret);
	if (ast->right)
		ret += print_node(ast->right, "right", depth + 1);
	ret += ft_printf("%*s", depth * 14, "");
	ret += ft_printf(".. %5s %d ..%s\n", name, depth, "");
	ret += ft_printf("%*s", (depth * 14) + 1, "");
	if (ast->left_arg)
		ret += ft_printf("%s ", ast->left_arg->val);
	if (ast->token)
		ret += ft_printf("%s", ast->token->val);
	if (ast->right_arg)
		ret += ft_printf(" %s", ast->right_arg->val);
	ret += ft_printf("\n");
	ret += ft_printf("%*s", depth * 14, "");
	ret += ft_printf(".............%s\n", "");
	if (ast->left)
		ret += print_node(ast->left, "left", depth + 1);
	return (ret);
}

int
	print_ast(t_ast *ast)
{
	int ret;

	ret = 0;
	if (ast)
	{
		ret += ft_printf("\n--- AST ---\n\n");
		ret += print_node(ast, "begin", 0);
		ret += ft_printf("\n-----------\n");
	}
	return (ret);
}
