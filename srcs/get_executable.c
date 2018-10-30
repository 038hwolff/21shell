/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_executable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:05:55 by hwolff            #+#    #+#             */
/*   Updated: 2018/10/30 17:08:59 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

int		ex_exec_core(t_data *data, char **paths)
{
	int		i;
	int		q;

	i = 0;
	signal(SIGINT, SIG_DFL);
	while (paths[i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			if ((q = execve(paths[i], data->args, data->env)) == -1)
				;
			break ;
		}
		i++;
	}
	cmd_not_found(data);
	return (0);
}

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
	signal(SIGINT, handle_signal);
	data->childpid = 0;
	free_tab(&data->args);
	free_tab(&paths);
	return (1);
}