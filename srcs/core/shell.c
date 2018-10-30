/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:47:05 by hben-yah          #+#    #+#             */
/*   Updated: 2018/10/30 19:48:59 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		g_reset_entry = 1;
		ft_putchar('\n');
		ft_putstr("$> ");
	}
}

char	**get_path(t_data *data)
{
	char	**path;
	int		i;
	char	*tmp;

	i = 0;
	if ((!(path = NULL) && data->args[0][0] != '/')
			&& !(ft_strnequ(data->args[0], "./", 2)))
	{
		while (data->env[i] && (ft_strncmp(data->env[i], "PATH=", 5) != 0))
			i++;
		if (!data->env[i] || !(path = ft_strsplit(data->env[i], ':')))
			return (NULL);
		path[0] = ft_strncpy(path[0], path[0] + 5, ft_strlen(path[0]));
		i = -1;
		while (path[++i])
		{
			tmp = path[i];
			if (!(path[i] = tristrjoin(path[i], "/", data->args[0])))
				return (NULL);
			free(tmp);
		}
	}
	return (path ? path : ft_tabdup(&data->args[0], 0));
}

char	**split_for_display(char *entry)
{
	char	**table;
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	if (!(table = ft_split_whitespaces(entry)))
		return (NULL);
	while (table[i])
	{
		j = ft_strlen(table[i]) - 1;
		while (ft_strlen(table[i]) > 1
				&& ((table[i][0] == '"' && table[i][j] == '"')
					|| (table[i][0] == '\'' && table[i][j] == '\'')))
		{
			if (!(tmp = ft_strsub(table[i], 1, ft_strlen(table[i]) - 2)))
				return (NULL);
			ft_strdel(&table[i]);
			table[i] = tmp;
		}
		i++;
	}
	return (table);
}

int		global_parse(t_data *data)
{
	expansions(data);
	if (!(data->args = split_for_display(data->entry)))
		return (0);
	if (data->args[0] && (is_builtins(data) == 0))
		return (ex_exec(data));
	free_tab(&data->args);
	return (1);
}

int		main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		z;

	(void)argv;
	(void)argc;
	if (!(data.env = ft_tabdup(envp, 0)))
		return (0);
	data.entry = NULL;
	signal(SIGINT, handle_signal);
	while (1)
	{
		display_prompt();
		if ((z = read_entry(&data)) > 0)
		{
			global_parse(&data);
			ft_strdel(&(data.entry));
		}
	}
	free_tab(&data.env);
	free_tab(&data.args);
	ft_putstr("\n");
	return (0);
}

/*
***************************************************************************
** main PAULINE
**
	int		main(int ac, char **av)
	{
	//	t_built built;
		(void)ac;
		(void)av;
		t_env 	*env;

		env = (t_env *)ft_memalloc(sizeof(t_env));
		setup_env(ac, av, env);
		display_prompt();
		loop(env);
			//SIGNAL_HANDLER
			//TERMCAPS -- EDITLINE
			//run = is_builtins(&built);
		return (0);
	}
****************************************************************************
*/

/*
****************************************************************************
** main HEIDY
**

	t_data	*get_data(void)
	{
		static t_data	*data = NULL;

		if (!data)
			data = (t_data*)ft_memalloc(sizeof(t_data));
		return (data);
	}

	void	check_term(void)
	{

	}

	void	init_data(int ac, char **av, char **env)
	{
		t_data	*data;

		if (ac && av && env)
			;
		data = get_data();
		data->on = 1;
	}

	int		read_input(void)
	{
		return (1);
	}

	void	lex_input(void)
	{

	}

	int		parse_input(void)
	{
		return (1);
	}

	void	execute_input(void)
	{

	}

	int		main(int ac, char **av, char **env)
	{
		t_data	*data;

		data = get_data();
		
		check_term();
		init_data(ac, av, env);
		while (data->on)
		{
			while (read_input() == -1)
				;
			lex_input();
			if (parse_input())
				execute_input();
			ft_printf("\n");
		}	
		return (EXIT_SUCCESS);
	}
*/
