/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:54:11 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/13 14:37:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

//char *g_line_test;


void 	print_lex(t_token *token, char *name)
{
	ft_printf("\n--- %s ---\n", name);
	while (token)
	{
		ft_printf("%s (%d) => %d\n", token->val, token->length,
			token->type);
		token = token->next;
	}
	ft_printf("--------------\n\n");
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
		read_command_line();

		//data->cmd_line = g_line_test;
		//ft_printf("%s\n", data->cmd_line);
		if (!data->errno && !(data->errno = 0))
		{

			lexical_analysis(&data->token, data->edl.line);

			// print le lex
			print_lex(data->token, "LEXER");
			//data->shell_exit = 1;
			if (parser(data))
			{
				print_lex(data->token, "PARSER");
				//ft_printf("%s\n", data->cmd_line);	*/
				build_ast(data);
				print_ast(data->ast);
				//execute(/* ??? */);
			}
		}
		data->token = NULL;  // FAUT FREE EN FAIT, A FAIRE PLUS TARD
		/*else
		{
			// free lex
			// mettre retour à > 0
		}
		ft_printf("\n");*/
	}	
}

int		main(int ac, char **av, char **env)
{
	t_env *envv;

	envv = (t_env *)ft_memalloc(sizeof(t_env));
	setup_env(ac, av, envv);
	if (ac && av && env)
	{
		init_shell(env);
		command_line_loop();
		//// free des trucs
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
