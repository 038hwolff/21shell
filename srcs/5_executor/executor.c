/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:08:39 by hwolff            #+#    #+#             */
/*   Updated: 2018/12/12 18:24:15 by hwolff           ###   ########.fr       */
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

int     executor(t_data *data, t_ast *ast)
{
	int ret;

	ret = 0;
	if (!ast)
		return (0);
	if (ast->type == 0)
		ret = ex_exec(data, data->exec->env,
			data->exec->bin, ast);
	else if (ast->type == 1)
		ret = exec_redirect(data, ast);
	else if (ast->type == 2)
		ret = exec_back_redirect(data, ast);
	else if (ast->type == 3)
		ret = main_agregator(data, ast);
	else if (ast->type == 4)
		ret = exec_pipes(data, ast);
	else if (ast->type == 5 || ast->type == 6)
		ret = execute_conditions(data, ast);
	else if (ast->type == 7)
		ret = execute_semicolon(data, ast);
	if (ast->type == 0)
		g_data->exe = ret;
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

int		ex_exec(t_data *data)
{
	char	**paths;
	int		status;

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
	free_tab(&paths);
	return (1);
}
