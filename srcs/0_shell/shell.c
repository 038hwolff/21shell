/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:54:11 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/17 15:24:42 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

//char *g_line_test;

int print_lex(t_token *token, char *name)
{
	int ret;

	ret = 0;
	ret += ft_printf("\n--- %s ---\n", name);
	while (token)
	{
		ret += ft_printf("%s (%d) => %d\n", token->val, token->length,
			token->type);
		token = token->next;
	}
	ret += ft_printf("--------------\n\n");
	return (ret);
}

/*
** Command line lifecycle
** - display prompt
** 1 - read the command line
** 2 - lexical analysis (lex)
** 3 - parsing (check syntax error, inhibitors, etc)
** 4 - building the ast (abstract syntaxic tree)
** 5 - execute the commands with priorities
*/

void	command_line_loop(void)
{
	t_data	*data;

	data = get_data();
	setup_hist(&data->hist);

	while (!data->shell_exit)
	{
		read_line();
		lexical_analysis(&data->token, data->edl.line);
		SHPRINT && print_lex(data->token, "LEXER");
		if (parser(data))
		{
			SHPRINT && print_lex(data->token, "PARSER");
			//ft_printf("%s\n", data->cmd_line);	*/
			build_ast(data);
			SHPRINT && print_ast(data->ast);
			SHPRINT && ft_printf("\n--- EXECUTION ---\n");
			exec_cmd_line(data, data->ast);
			SHPRINT && ft_printf("-----------------\n");
		}
		reset_command(data);
	}
}

int		main(int ac, char **av, char **env)
{
	if (ac && av && env)
	{
		init_shell(env);
		command_line_loop();
		//// free des trucs
		// free hist
	}
	return (EXIT_SUCCESS);
}

/* main de test heidy
int		main(int ac, char **av, char **env)
{
	if (ac && av && av[1] && env)
	{
		g_line_test = av[1];
		init_shell(env);
		command_line_loop();
		//// free des trucs
	}
	return (EXIT_SUCCESS);
}*/
