/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_agregator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:48:02 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/18 08:48:03 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** 2> : redirige les erreurs dans un fichier (s'il existe déjà, il sera écrasé);
** 2>&1 : redirige les erreurs au même endroit et de la même façon que la
** sortie standard
**          ne fonctionne que sur ksh;
** 2>&- : ferme la sortie indiquee
** >& : est egal a 2>&1, mais ne fonctionne que sur csh ou tcsh
** 1>&2
*/

static int		check_fd(int fd)
{
	int		dfd;

	if ((dfd = dup(fd)) == -1)
		return (0);
	close(dfd);
	return (1);
}

int				main_agregator(t_data *data, t_ast *ast)
{
	int		ret;
	int		fd[2];
	int		dfd;

	fd[0] = ast->left_arg ? ft_atoi(ast->left_arg->val) : 2;
	fd[1] = ast->right_arg ? ft_atoi(ast->right_arg->val) : 1;
	if (ast->right_arg && ((*ast->right_arg->val != '-' && fd[1] > 10)
		|| !check_fd(fd[1])))
		return (!fd_exception(ast->right_arg->val));
	fd[1] < 0 && (fd[1] = 0);
	dfd = dup(fd[0]);
	if (ast->right_arg && *ast->right_arg->val != '-'
		&& (fd[1] != 0
			|| (ast->left_arg && !ft_strequ(ast->left_arg->val, "0"))))
		dup2(fd[1], fd[0]);
	else
		close(fd[0]);
	if (ast->right)
		ret = exec_cmd_line(data, ast->right);
	if (ast->left)
		ret = exec_cmd_line(data, ast->left);
	dup2(dfd, fd[0]);
	close(dfd);
	return (ret);
}
