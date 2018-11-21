/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:54:11 by hben-yah          #+#    #+#             */
/*   Updated: 2018/11/19 17:23:52 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	command_line_loop(void)
{
	t_data	*data;

	data = get_data();
	while (!data->shell_exit)
	{
		display_prompt();
		read_command_line();
	//	ft_printf("%s\n", data->cmd_line);	
	/*	if (!data->errno && !(data->errno = 0))
		{
			lexical_analysis(&data->token, data->cmd_line);*/
			//if (!parse())
			//{
				//build_ast(/* ??? */);
				//execute(/* ??? */);
			//}
/*		}
		else
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
