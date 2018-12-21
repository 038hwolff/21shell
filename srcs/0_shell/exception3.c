/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:18:07 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/21 19:18:20 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		file_not_found_exception(char *file)
{
	ft_dprintf(STDERR_FILENO,
						""ERR_PREFIX"%s: No such file or directory\n", file);
	return (0);
}
