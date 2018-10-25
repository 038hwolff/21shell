/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:47:05 by hben-yah          #+#    #+#             */
/*   Updated: 2018/10/25 18:33:54 by hwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

int		main(int ac, char **av, char **env)
{
	t_built built;
	(void)ac;
	(void)av;

	if (ac && av && env)
	{
		is_builtins(&built);
	}
	return (0);
}