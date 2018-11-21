/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:54:11 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/20 17:53:29 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char *g_line_test;


void 	print_lex(t_token *token)
{
	ft_printf("\n---LEXAGE---\n");
	while (token)
	{
		ft_printf("%s (%d) => %d\n", token->val, token->length,
			token->type);
		token = token->next;
	}
	ft_printf("------------\n");
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
	while (!data->shell_exit)
	{
		display_prompt();
		
		//read_command_line();

		data->cmd_line = g_line_test;

		if (!data->errno && !(data->errno = 0))
		{
			lexical_analysis(&data->token, data->cmd_line);
			// print le lex
			print_lex(data->token);
			data->shell_exit = 1;

			if (!parse(data, data->token))
			{
				//ft_printf("%s\n", data->cmd_line);	
				//build_ast(/* ??? */);
				//execute(/* ??? */);
			}
		}
		else
		{
			// free lex
			// mettre retour à > 0
		}
		ft_printf("\n");
	}	
}

/* real main
int		main(int ac, char **av, char **env)
{
	if (ac && av && env)
	{
		init_shell(env);
		command_line_loop();
		//// free des trucs
	}
	return (EXIT_SUCCESS);
}
*/

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
}