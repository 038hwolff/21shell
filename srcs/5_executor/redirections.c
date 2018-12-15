/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:08:32 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/14 15:23:37 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

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
	pid_t	pid;

	ret = open(ast->right_arg->val, O_RDONLY);
	if (ret >= 0)
	{
		pid = fork();
		dup2(ret, 0);
		close(ret);
		if (ast->right)
			ret = execute(data, ast->right);
		if (ast->left)
			ret = execute(data, ast->left);
	 	return (ret);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"error -- %s\n");
		return (1);
	}
}

int		exec_redirect(t_data *data, t_ast *ast, int rafter)
{
	int		ret;
	int		fd;

	ret = 0;
	if (rafter == GREAT)
		ret = open(ast->right_arg->val, O_CREAT | O_WRONLY, 0644);
	else if (rafter == DOUBLEGREAT)
		ret = open(ast->right_arg->val, O_CREAT | O_WRONLY | O_APPEND);
	if (ret >= 0)
	{
		fd = ast->left_arg ? ft_atoi(ast->left_arg->val) : 1;
		dup2(ret, fd);
		close(ret);
		if (ast->right)
			ret = execute(data, ast->right);
		if (ast->left)
			ret = execute(data, ast->left);
	 	return (ret);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, ""ERR_PREFIX"error -- %s\n");
		return (1);
	}
}
