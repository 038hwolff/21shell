/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:03:53 by hben-yah          #+#    #+#             */
/*   Updated: 2018/12/23 01:09:06 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

/*
** Headers
*/

# include <stdio.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>

/*
** Bonus headers
*/

# include <dirent.h>

/*
** Libs
*/

# include "libft.h"
# include <term.h>

/*
** Defines
*/

# include "define.h"

/*
** Typedef / Structs
*/

# include "struct.h"

/*
** Headers 21sh
*/

# include "a_shell.h"
# include "b_lineeditor.h"
# include "c_lexer.h"
# include "d_parser.h"
# include "e_astbuilder.h"
# include "f_executor.h"
# include "g_builtins.h"

/*
** Globals
*/

t_data				g_sh_data;
int					g_reset_entry;

#endif
