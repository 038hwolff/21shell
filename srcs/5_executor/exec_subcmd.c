/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subcmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:54:54 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/06 20:32:42 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_data
	*init_subshell(char **env)
{
	t_data *data;

	try_m(data = (t_data*)ft_memalloc(sizeof(t_data)));
	try_m((data->env = ft_strtabdup(env)));
	try_m((data->loc = ft_strtabnew(0)));
	try_m((data->edl.line = ft_strnew(0)));
	data->subcmd = 1;
	return (data);
}

int
	subshell(int ac, char **av, char **env)
{
	t_data		*data;
	int			status;
	char		*tmp;
	int			i;

	data = init_subshell(env);
	status = 0;
	i = 0;
	while (i < ac)
	{
		ft_asprintf(&tmp, "%s %s%s", data->edl.line, av[i],
													(i + 1 == ac ? "\n" : ""));
		try_m(tmp);
		ft_strdel(&data->edl.line);
		data->edl.line = tmp;
		++i;
	}
	lexical_analysis(&data->token, data->edl.line);
	if (parser(data))
	{
		build_ast(data);
		status = exec_cmd_line(data, data->ast);
	}
	reset_subshell(data);
	return (status);
}

char
	**tokens_to_tab(t_token *token)
{
	char	**table;
	char	**p;
	int		nbword;

	nbword = count_token(token);
	try_m((table = (char **)ft_memalloc(sizeof(char *) * (nbword + 1))));
	p = table;
	while (token)
	{
		try_m((*p = ft_strdup(token->val)));
		token = token->next;
		++p;
	}
	return (table);
}

char
	exec_subcmd(t_data *data, t_ast *ast)
{
	pid_t		pid;
	int			status;
	char		**table;

	status = 0;
	if (!ast || !ast->token)
		return (RET_OK);
	if (!(table = tokens_to_tab(ast->token)))
		return (RET_MAJ_ERROR);
	if ((pid = fork()) == -1)
		return (RET_MAJ_ERROR);
	else if (pid == 0)
		exit(subshell(ft_strtablen(table) - 2, table + 1, data->env));
	else
	{
		signal(SIGINT, SIG_IGN);
		pid = wait(&status);
		ft_tabdel((void ***)&table);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	ft_tabdel((void ***)&table);
	return (RET_OK);
}
