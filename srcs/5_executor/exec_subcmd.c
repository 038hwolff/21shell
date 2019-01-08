/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subcmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:54:54 by hben-yah          #+#    #+#             */
/*   Updated: 2019/01/08 21:57:17 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void
	args_to_cmd_line(t_data *data, int ac, char **av)
{
	char	*tmp;
	int		i;

	try_m((data->edl.line = ft_strnew(0)));
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
}

int
	subshell(t_data *data, int ac, char **av)
{
	int			status;

	reset_command(data);
	data->subcmd = 1;
	status = 0;
	args_to_cmd_line(data, ac, av);
	lexical_analysis(&data->token, data->edl.line);
	if (parser(data))
	{
		build_ast(data);
		status = exec_cmd_line(data, data->ast);
	}
	reset_shell(data);
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

	if ((status = 0) || !ast || !ast->token)
		return (RET_OK);
	if (!(table = tokens_to_tab(ast->token)))
		return (RET_MAJ_ERROR);
	if ((pid = fork()) == -1)
		status = RET_MAJ_ERROR;
	else if (pid == 0)
		status = subshell(data, ft_strtablen(table) - 2, table + 1);
	else
	{
		signal(SIGINT, SIG_IGN);
		pid = wait(&status);
		ft_tabdel((void ***)&table);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	ft_tabdel((void ***)&table);
	if (!pid)
		exit(status);
	return (RET_OK);
}
