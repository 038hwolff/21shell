/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:08:32 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/16 19:50:54 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** > : redirige dans un fichier et l'écrase s'il existe déjà ;
** >> : redirige à la fin d'un fichier et le crée s'il n'existe pas.
** < : envoie le contenu d'un fichier à une commande ;
** << : passe la console en mode saisie au clavier, ligne par ligne (heredoc).
** Toutes ces lignes seront envoyées à la commande lorsque le mot-clé de fin
** aura été écrit.
** 2>> et 2> OK
*/

int		exec_back_redirect(t_data *data, t_ast *ast)
{
	int		ret;
	int		stdin;

	ret = open(ast->right_arg->val, O_RDONLY);
	if (ret >= 0)
	{
		stdin = dup(0);
		dup2(ret, 0);
		ret = 0;
		if (ast->right)
			ret = exec_cmd_line(data, ast->right);
		if (ast->left)
			ret = exec_cmd_line(data, ast->left);
		dup2(stdin, 0);
		close(ret);
		return (ret);
	}
	else
	{
// file permission ???
		ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"error -- %s\n");
		return (1);
	}
}

int		exec_redirect(t_data *data, t_ast *ast, int rafter)
{
	int		ret;
	int		fd;
	int		stdin;

	ret = 0;
	if (rafter == GREAT)
		ret = open(ast->right_arg->val, O_CREAT | O_WRONLY, 0644);
	else if (rafter == DOUBLEGREAT)
		ret = open(ast->right_arg->val, O_CREAT | O_WRONLY | O_APPEND, 0644);
	ft_printf("gneee");
	if (ret >= 0)
	{
		fd = (ast->left_arg ? ft_atoi(ast->left_arg->val) : 1);
		stdin = dup(fd);
		dup2(ret, fd);
		ret = 0;
		if (ast->right)
			ret = exec_cmd_line(data, ast->right);
		if (ast->left)
			ret = exec_cmd_line(data, ast->left);
		dup2(stdin, fd);
		close(stdin);
		return (ret);
	}
	else
	{
		file_permission_exception(ast->right_arg ? ast->right_arg->val : "");
		return (1);
	}
}
