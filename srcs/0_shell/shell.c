/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:38:24 by hwolff            #+#    #+#             */
/*   Updated: 2019/01/11 21:06:18 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		print_lex(t_token *token, char *name)
{
	int			ret;

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

void	set_return_value(t_data *data, int ret)
{
	char	*s;

	s = NULL;
	ft_asprintf(&s, "%d", ret);
	var_set(&data->spe, "?", s);
	ft_strdel(&s);
}

void	add_command_to_history(t_data *data)
{
	char *new;

	try_m(new = ft_strsub(data->command, 0, ft_strlen(data->command) - 1));
	if (data->hist.h_count == 0
		|| !ft_strequ(data->hist.list[data->hist.h_count - 1], new))
		data->hist.list = add_history(new, &data->hist);
	else
		ft_strdel(&new);
}

void	command_line_loop(void)
{
	t_data		*data;
	int			ret;

	data = get_data();
	setup_hist(&data->hist);
	while ((ret = -1))
	{
		read_line();
		lexical_analysis(&data->token, data->edl.line);
		while ((ret = parser(data)) == -1)
			lexical_analysis(&data->token, data->edl.line);
		if (ret)
		{
			add_command_to_history(data);
			data->dev && print_lex(data->token, "PARSER");
			build_ast(data);
			data->dev && print_ast(data->ast);
			data->dev && ft_printf("\n--- EXECUTION ---\n");
			ret = exec_cmd_line(data, data->ast);
			data->dev && ft_printf("-----------------\n");
			set_return_value(data, ret);
		}
		reset_command(data);
	}
}

int		main(int ac, char **av, char **env)
{
	if (ac && av && env)
	{
		init_shell(env, ac, av, (ac > 1 && ft_strequ(av[1], "-dev")));
		command_line_loop();
	}
	return (EXIT_SUCCESS);
}
