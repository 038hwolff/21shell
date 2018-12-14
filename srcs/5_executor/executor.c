/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:08:39 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/14 11:43:28 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** 7 - ; or &(jobs)
** 6 - ||
** 5 - &&
** 4 - |
** 3 - >&
** 2 - < or <<
** 1 - > or >>
** 0 - CMD
*/

int     execute(t_data *data, t_ast *ast)
{
	int rank;
	int ret;

	if (!ast)
		return (0);
	ret = 0;
	rank = get_rank(ast->token->type);
	if (rank == WORD)
		ret = ex_exec(data, ast);
	if (rank == ASSIGNEMENT_WORD)
		ret = set_local_var(data, ast);
	else if (rank == GREAT || rank == DOUBLEGREAT)
		ret = exec_redirect(data, ast, rank);
	else if (rank == LESS)
		ret = exec_back_redirect(data, ast);
	else if (rank == 3)
		ret = main_agregator(data, ast);
	else if (rank == 4)
		ret = exec_pipes(data, ast);
	else if (rank == 5 || rank == 6)
		ret = execute_conditions(data, ast);
	else if (rank == 7)
		ret = execute_semicolon(data, ast);
	if (rank == 0)
		data->exe_return = ret;
	return (ret);
}

// char	**get_path(t_data *data)
// {
// 	char	**path;
// 	int		i;
// 	char	*tmp;

// 	i = 0;
// 	if ((!(path = NULL) && data->args[0][0] != '/')
// 			&& !(ft_strnequ(data->args[0], "./", 2)))
// 	{
// 		while (data->env[i] && (ft_strncmp(data->env[i], "PATH=", 5) != 0))
// 			i++;
// 		if (!data->env[i] || !(path = ft_strsplit(data->env[i], ':')))
// 			return (NULL);
// 		path[0] = ft_strncpy(path[0], path[0] + 5, ft_strlen(path[0]));
// 		i = -1;
// 		while (path[++i])
// 		{
// 			tmp = path[i];
// 			if (!(path[i] = tristrjoin(path[i], "/", data->args[0])))
// 				return (NULL);
// 			free(tmp);
// 		}
// 	}
// 	return (path ? path : ft_tabdup(&data->args[0], 0));
// }





// int		ex_exec_core(t_data *data, char **paths)
// {
// 	int		i;
// 	int		q;

// 	i = 0;
// //	signal(SIGINT, SIG_DFL);
// 	while (paths[i])
// 	{
// 		if (access(paths[i], X_OK) == 0)
// 		{
// 			if ((q = execve(paths[i], data->args, data->env)) == -1)
// 				;
// 			break ;
// 		}
// 		i++;
// 	}
// 	cmd_not_found(data);
// 	return (0);
// }

int		ex_exec(t_data *data, t_ast *ast)
{
	(void)data;
	(void)ast;
	/*char	**paths;
	int		status;

	(void)ast;
	if (!(paths = get_path(data)))
	{
		ft_putendl("Error: Path is empty");
		free_tab(&data->args);
		free_tab(&paths);
		return (0);
	}
	data->childpid = fork();
	if (data->childpid == 0)
		ex_exec_core(data, paths);
	else
		signal(SIGINT, SIG_IGN);
	wait(&status);
	if (WIFSIGNALED(status))
		ft_putchar('\n');
//	signal(SIGINT, handle_signal);
	data->childpid = 0;
	free_tab(&data->args);
	free_tab(&paths);*/
	return (1);
}

int set_local_var(t_data *data, t_ast *ast)
{
	(void)data;
	(void)ast;
	return (0);
}

int execute_conditions(t_data *data, t_ast *ast)
{
	(void)data;
	(void)ast;
	return (0);
}

int execute_semicolon(t_data *data, t_ast *ast)
{
	(void)data;
	(void)ast;
	return (0);
}

char	**get_path(t_data *data)
{
	(void)data;
	// char	**path;
	// int		i;
	// char	*tmp;

	// i = 0;
	// if ((!(path = NULL) && data->args[0][0] != '/')
	// 		&& !(ft_strnequ(data->args[0], "./", 2)))
	// {
	// 	while (data->env[i] && (ft_strncmp(data->env[i], "PATH=", 5) != 0))
	// 		i++;
	// 	if (!data->env[i] || !(path = ft_strsplit(data->env[i], ':')))
	// 		return (NULL);
	// 	path[0] = ft_strncpy(path[0], path[0] + 5, ft_strlen(path[0]));
	// 	i = -1;
	// 	while (path[++i])
	// 	{
	// 		tmp = path[i];
	// 		if (!(path[i] = tristrjoin(path[i], "/", data->args[0])))
	// 			return (NULL);
	// 		free(tmp);
	// 	}
	// }
	// return (path ? path : ft_tabdup(&data->args[0], 0));
	return (NULL);
}
