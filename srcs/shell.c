/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:47:05 by hben-yah          #+#    #+#             */
/*   Updated: 2018/10/29 21:26:07 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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